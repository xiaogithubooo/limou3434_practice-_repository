//单例模式——懒汉模式
#include <iostream>
using namespace std;

//懒汉模式：第一次用的时候再创建（现吃现做）
template <class Type>
class SlackerModel
{

};



////饿汉模式：把对象提前创建好（最好是在 程序/main 启动时），并且随时需要（不要使用全局变量来实现，一是无法直接创建，二是容易重定义，应该使用静态变量）
//template <class Type>
//class HungryManModel
//{
//public:
//	static HungryManModel* GetInstance() //4.获取实例对象，并且由于用户无法直接创建对象，这个函数也必须静态成员函数，方便用户调用
//	{
//		return &_inst; //5.返回单例对象
//	}
//
//	HungryManModel(const HungryManModel<Type>& self) = delete; //12.禁用拷贝构造
//
//	HungryManModel& operator =(const HungryManModel<Type>& self) = delete; //14.禁用赋值重载（一般禁用拷贝构造也会禁用赋值重载）
//
//	//6.这里再加上对单例对象的一些操作方法
//	void Add()
//	{
//		_data++;
//	}
//
//	void Print()
//	{
//		cout << "数据:" << _data << endl;
//	}
//
//private:
//	HungryManModel() //2.将构造函数私有化，禁止用户直接在类外构造对象
//		: _data(Type())
//	{}
//
//private:
//	Type _data; //1.对象内部的数据，假设在全局独有这一份
//	static HungryManModel<Type> _inst; //3.设置静态成员变量，使得在 main() 被调用前就构造好单例对象，注意这个静态成员的内部并没有自己包含自己，因为静态变量存储在静态区，而不在对象内部
//};
//
//template <class Type>
//HungryManModel<Type> HungryManModel<Type>::_inst; //虽然在类外定义，但是该静态变量是属于类的（静态成员），因此可以调用构造函数
//
//int main()
//{
//	//HungryManModel<int> a; //7.无法直接在类外直接创建对象
//	//HungryManModel<int>* pa = new HungryManModel<int>(); //8.无法直接在类外直接创建对象
//	HungryManModel<int>* p = HungryManModel<int>::GetInstance(); //9.获取单例对象
//
//	//10.调用单例对象的方法
//	p->Add();
//	p->Print(); //输出 1
//	HungryManModel<int>::GetInstance()->Add();
//	HungryManModel<int>::GetInstance()->Print(); //输出 2
//
//	//11.发现还有一个缺陷：没有禁用拷贝构造，上述类依旧是有问题的，下面代码的就暴露出拷贝问题
//	//HungryManModel<int> copy(*HungryManModel<int>::GetInstance()); //拷贝
//
//	//HungryManModel<int>::GetInstance()->Add();
//	//HungryManModel<int>::GetInstance()->Print(); //输出 3
//
//	//copy.Print(); //依旧输出 2
//
//	//13.甚至还有一些奇奇怪怪的操作，自己给自己赋值...虽然也不会有什么问题啦，以防万一，我们也把赋值重载给禁掉
//	//*HungryManModel<int>::GetInstance() = *HungryManModel<int>::GetInstance();
//
//	//15.允许创建不同类型的单例对象，但是每一种类型的对象在代码中都只会存在一份
//	HungryManModel<double>::GetInstance()->Add();
//	HungryManModel<double>::GetInstance()->Print();
//
//	HungryManModel<long>::GetInstance()->Add();
//	HungryManModel<long>::GetInstance()->Print();
//	return 0;
//}
