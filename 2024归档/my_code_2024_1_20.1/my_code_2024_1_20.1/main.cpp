//使用 const_cast <> 的典型例子
#include <iostream>

struct type
{
    int _i;

    type(int i) :
        _i(3)
    {}

    void f(int v) const //2.2.展开等价于 const type const * this
    {
        //this->_i = v;                    //2.3.编译错误：this 是指向 const 的指针
        const_cast<type*>(this)->_i = v;   //2.4.由于调用的对象不是 const，因此这里就是 OK 的，修改没有带来危险
    }
};

int main()
{
    //1.使用普通的内置类型时
    int i = 3;                 //1.1.不声明 i 为 const
    const int& rci = i;        //1.2.常引用（但是引用的对象却不是 const 类型的）
    //rci = 4;                 //1.3.修改失败，明明 i 这个对象可以被修改，但是由于使用了常引用，导致无法修改（哪怕我们修改了 i 也不会什么危险）
    const_cast<int&>(rci) = 4; //1.4.修改成功，并且 i 的修改不会带来危险，毕竟 i 本身就可以被修改，只需要保证 rci 这个引用不能修改 i 值即可
    std::cout << "i = " << i << '\n';

    //2.使用用户的自定义类型时
    type t(3);
    t.f(4); //2.1.由于 struct 中没有定义非 const 的 f()，只有 const 类型的 f()，因此会调用 const 版本的 f()
    std::cout << "type::_i = " << t._i << '\n';

    //3.如果上述定义的时 const type t，那么使用 t.f(4) 将会是未定义行为，这点需要尤其注意

    return 0;
}