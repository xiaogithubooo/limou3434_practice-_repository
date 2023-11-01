#include <iostream>
#include <string>
using namespace std;
class A
{
public:
    A(const char* s) { cout << s << endl; }
    ~A() {}
    int _a;
};

class B : public A
{
public:
    B(const char* s1, const char* s2) : A(s1) 
    { 
        cout << s2 << endl;
    }
    int _b;
};

class C : public A
{
public:
    C(const char* s1, const char* s2) : A(s1)
    {
        cout << s2 << endl;
    }
    int _c;
};

class D : public C, public B//多继承，并且是菱形继承
{
public:
    D(const char* s1, const char* s2, const char* s3, const char* s4)
        : B(s1, s2), C(s1, s3)//, A(s1)//这里没有虚继承了就不可以使用最后一个构造函数了
    {
        cout << s4 << endl;
    }
};

int main()
{
    D* p = new D("class A", "class B", "class C", "class D");
    delete p;
    return 0;
}

//#include <iostream>
//#include <string>
//using namespace std;
//class A
//{
//public:
//    A(const char* s) { cout << s << endl; }
//    ~A() {}
//    int _a;
//};
//
//class B : virtual public A
//{
//public:
//    B(const char* s1, const char* s2) : A(s1) { cout << s2 << endl; }
//    int _b;
//};
//
//class C : virtual public A
//{
//public:
//    C(const char* s1, const char* s2) : A(s1) { cout << s2 << endl; }
//    int _c;
//};
//
//class D : public B, public C//多继承，并且是虚继承
//{
//public:
//    D(const char* s1, const char* s2, const char* s3, const char* s4)
//        : B(s1, s2), C(s1, s3), A(s1)
//    {
//        cout << s4 << endl;
//    }
//};
//
//int main()
//{
//    D* p = new D("class A", "class B", "class C", "class D");
//    delete p;
//    return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class A//父类A
//{
//public:
//    int _a;
//};
//
//class B : public A//子类B
//{
//public:
//    int _b;
//};
//
//class C : public A//子类C
//{
//public:
//    int _c;
//};
//
//class D : public B, public C//多继承后的子子类D
//{
//public:
//    int _d;
//};
//
//int main()
//{
//    D d;
//
//    //1.赋值给_a，但是由于产生了二义性，赋值失败
//    //d._a = 0;
//
//    //2.使用::指定访问_a，勉强解决了二义性，但是出现了数据冗余（有两个_a继承自不同的父类）
//    d.B::_a = 1;
//    d.C::_a = 2;
//    cout << d.B::_a << " " << d.C::_a << endl;
//
//    //3.由于没有二义性问题，因此不需要使用::
//    d._b = 3;//或者d.B::_b = 3;
//    d._c = 4;//或者d.C::_c = 4;
//    cout << d._b << " " << d._c << endl;
//
//    d._d = 5;
//    return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class A
//{
//public:
//    A(const char* s) { cout << s << endl; }
//    ~A() {}
//    int _a;
//};
//
//class B : virtual public A
//{
//public:
//    B(const char* s1, const char* s2) : A(s1) { cout << s2 << endl; }
//    int _b;
//};
//
//class C : virtual public A
//{
//public:
//    C(const char* s1, const char* s2) : A(s1) { cout << s2 << endl; }
//    int _c;
//};
//
//class D : public C, public B//多继承，并且是虚继承
//{
//public:
//    D(const char* s1, const char* s2, const char* s3, const char* s4)
//        : B(s1, s2), C(s1, s3), A(s1)
//    {
//        cout << s4 << endl;
//    }
//};
//
//int main()
//{
//    D* p = new D("class A", "class B", "class C", "class D");
//    delete p;
//    return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//    void Print()
//    {
//        cout << "name:" << _name << endl;
//        cout << "age:" << _age << endl;
//    }
//protected:
//    string _name = "peter";
//    int _age = 18;
//};
//
//class Student : public Person
//{
//protected:
//    int _stuid;
//};
//
//class Teacher : public Person
//{
//protected:
//    int _jobid;
//};
//
//int main()
//{
//    Person per;//父类对象
//
//    //1.子类对象引用父类
//    //Student& rstu = per;//不允许
//    //Student& rstu = (Student)per;//不允许
//
//    //2.子类指针指向父类
//    //Student* pstu = &per;//不允许
//    Student* pstu = (Student*)&per;//虽然可以通过，但是很危险，有可能会越界
//
//    //3.这种操作我们以后有机会再来讨论（会涉及到 dynamic_cast 的使用）
//    Student std;
//    Person* pper = &std;
//    Student* pstd = (Student*)pper;//允许
//
//    return 0;
//}

//class Father
//{
//public:
//	Father(int f_val) : _f_number(f_val) {}
//	int _f_number;
//};
//class Child : public Father
//{
//public:
//	Child(int f_val, int c_val) : Father(f_val), _c_number(c_val) {}
//	int _c_number;
//};
//int main()
//{
//	//1.内置类型
//	int a1 = 1;
//	int a2 = 10;
//	a2 = a1;//没有临时变量产生，是比较自然天然的
//	int& a3 = a2;//成功
//
//	int b1 = 100;
//	double b2 = 3.14;
//	b2 = b1;//有临时变量产生
//	//double& b3 = b1;//失败
//	const double& b3 = b1;//成功
//
//	//2.自定义类型
//	Father n1(1);
//	Child n2(2, 3);
//	n1 = n2;//报警告，但是成功（只是将子类中的成员变量拷贝给父类）
//	Father n3 = n2;//报警告，但是成功（只是将子类中的成员变量拷贝给父类）
//	Father& n4 = n2;//成功
//	Father* n5 = &n2;//成功
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class A//父类A
//{
//public:
//    int _a;
//};
//
//class B : virtual public A//子类B
//{
//public:
//    int _b;
//};
//
//class C : virtual public A//子类C
//{
//public:
//    int _c;
//};
//
//class D : public B, public C//多继承后的子子类D
//{
//public:
//    int _d;
//};
//
//int main()
//{
//    D d;
//    d.A::_a = 1;
//    d._a = 2;
//
//    cout << d.B::_a << " " << d.C::_a << endl;//解决了二义性和冗余问题
//
//    d._b = 3;//或者d.B::_b = 3;
//    d._c = 4;//或者d.C::_c = 4;
//    cout << d._b << " " << d._c << endl;
//
//    d._d = 5;
//    return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class A//父类A
//{
//public:
//    int _a;
//};
//
//class B : public A//子类B
//{
//public:
//    int _b;
//};
//
//class C : public A//子类C
//{
//public:
//    int _c;
//};
//
//class D : public B, public C//多继承后的子子类D
//{
//public:
//    int _d;
//};
//
//int main()
//{
//    D d;
//
//    //1.赋值给_a，但是由于产生了二义性，赋值失败
//    //d._a = 0;
//
//    //2.使用::指定访问_a，勉强解决了二义性，但是出现了数据冗余（有两个_a继承自不同的父类）
//    d.B::_a = 1;
//    d.C::_a = 2;
//    cout << d.B::_a << " " << d.C::_a << endl;
//
//    //3.由于没有二义性问题，因此不需要使用::
//    d._b = 3;//或者d.B::_b = 3;
//    d._c = 4;//或者d.C::_c = 4;
//    cout << d._b << " " << d._c << endl;
//
//    d._d = 5;
//    return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//	Person() : _name("peter"), _age(18) { cout << "Person()" << endl; };
//	//类内成员变量
//	string _name;
//	int _age;
//};
//
//class Student : public Person
//{
//public:
//	Student() : Person(), _stuid(22103) { cout << "Student()" << endl; };
//
//	//类内成员变量
//	//Person::string _name;
//	//Person::int _age;
//	int _stuid;
//};
//
//class Teacher : public Person
//{
//public:
//	Teacher() : Person(), _jobid(88903) { cout << "Teacher()" << endl; };
//
//	//类内成员变量
//	//Person::string _name;
//	//Person::int _age;
//	int _jobid;
//};
//class Graduate : public Student, public Teacher//多继承
//{
//public:
//	//类内成员变量
//	//Student::Person::string _name;
//	//Student::Person::int _age;
//	//Student::int _stuid;
//	
//	//Teacher::Person::string _name;
//	//Teacher::Person::int _age;
//	//Teacher::int _jobid;
//
//	int _graid;
//};
//
//int main()
//{
//	Graduate g;
//	//cout << g._name << endl;//运行失败，具有二义性（这里到底是Student类的还是Teacher类的_name）
//	cout << g.Student::_name << endl;//运行成功，成功解决二义性
//	cout << g.Teacher::_name << endl;//运行成功，成功解决二义性
//	
//	//但是一个对象具有两个名字？这合理么？
//	//换句话说，如果是其他的字段，比如“身份证”这样的独有ID，不能存在两份吧？
//	//也就是说：菱形继承发生了数据冗余！
//	
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
////1.父类Person
//class Person
//{
//public:
//    Person(string name, int age) : _name(name), _age(age)//不是默认的构造函数
//    {
//        cout << "Person(string nume, int age) : _name(\"peter\"), _age(18)" << endl;
//    }
//    ~Person()
//    {
//        cout << "~Person()" << endl;
//    }
//    Person(Person& p)//不是默认的拷贝构造函数
//    {
//        cout << "Person(Person& p)" << endl;
//        _name = p._name;
//        _age = p._age;
//    }
//    Person& operator=(const Person& p)//不是默认的赋值重载函数
//    {
//        cout << "Person operator=(const Person& p)" << endl;
//        if (this != &p)
//        {
//            _name = p._name;
//            _age = p._age;
//        }
//        return *this;
//    }
//    void Print()
//    {
//        cout << "Print()" << endl;
//        cout << "name:" << _name << " age:" << _age << endl;
//    }
//protected:
//    string _name;
//    int _age;
//};
//
////2.子类Student
//class Student : public Person
//{
//public:
//    Student(string name, int age, int stuid = 00000000) : Person(name, age), _stuid(stuid)//这里调用显示调用父类的构造函数（并且没有明确指定父类成员，只是简写了父类成员变量的名字），初始化子类中从父类继承过来的成员，然后才初始化子类自己的成员
//    {
//        cout << "Student(string name, int age, int stuid = 00000000) : Person(name, age), _stuid(stuid)" << endl;
//    }
//    ~Student()
//    {
//        cout << "~Student()" << endl;
//        //无需自己调用父类函数的析构函数，编译器会自己帮助我们调用
//    }
//    Student(Student& s) : Person(s), _stuid(s._stuid)//这里使用了切片显式调用父类的拷贝构造函数（可以选择不指定父类），初学者推荐一直显式调用，有助于代码理解和可读性。
//    {
//        cout << "Student(Student& s) : Person(s), _stuid(s._stuid)" << endl;
//    }
//    Student& operator=(const Student& p)
//    {
//        cout << "Student& operator=(const Student& p)" << endl;
//        if (this != &p)
//        {
//            Person::operator=(p);
//            _stuid = p._stuid;
//        }
//        return *this;
//    }
//    void Print()//构成成员函数隐藏了
//    {
//        //Print();//这就变成自己调用自己了，此时就不可以不明确父类了
//        Person::Print();//指明父类
//        cout << "stuid:" << _stuid << endl;
//    }
//protected:
//    int _stuid;
//};
//int main()
//{
//    Student s1("limou", 18, 22130800);
//    Student s2(s1);
//    Student s3("daimou", 22, 22109988);
//    s1 = s3;
//
//    s1.Print();
//    s2.Print();
//    s3.Print();
//    return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class Person//父类  
//{
//public:
//	Person() : _name("Person"), _age(18) { cout << "Person() : _name(\"Person\"), _age(18)" << endl; }
//	void Print()
//	{
//		cout << "Person::void Print()" << endl;
//		cout << "Person::name:" << _name << endl;
//		cout << "Person::age:" << _age << endl << endl;
//	}
//	string _name;//姓名
//	int _age;//年龄 
//};
//
//class Student : public Person
//{
//public:
//	Student() : _name("Student"), _age(15) { cout << "Student() : _name(\"Student\"), _age(15)" << endl; }
//	void Print()
//	{
//		cout << "Student::void Print()" << endl;
//		cout << "Student::name:" << _name << endl;
//		cout << "Student::age:" << _age << endl;
//		cout << "Student::Person::name:" << Person::_name << endl;
//		cout << "Student::Person::age:" << Person::_age << endl << endl;
//	}
//	string _name;//姓名
//	int _age;//年龄 
//};
//
//int main()
//{
//	Person p;
//	Student s;
//
//	p.Print();
//	s.Print();
//
//	return 0;
//}

////单纯继承出空子类，没有隐藏/重定义
//#include <iostream>
//#include <string>
//using namespace std;
//class Person//父类  
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//	string _name = "peter";//姓名
//	int _age = 18;//年龄 
//};
//
//class Student : public Person {};
//class Teacher : public Person {};
//
//int main()
//{
//	Person p;
//	Student s;
//	Teacher t;
//
//	printf("%p\n", &Person::_name);
//	//在创建类的对象之前，类的成员变量不会拥有任何有效的内存地址，这些地址尚未分配
//	//当你尝试打印类内的成员变量地址时，如果类的对象尚未被创建，那么这些成员变量的地址有可能将是nullptr
//	//因此不能这么打印变量的地址，除非是静态成员变量
//
//	cout << endl << "打印成员变量地址:" << endl;
//	printf("%s, %p\n", p._name.c_str(), &p._name);
//	printf("%s, %p\n", s._name.c_str(), &s._name);
//	printf("%s, %p\n", t._name.c_str(), &t._name);
//
//	cout << endl << "打印成员函数地址:" << endl;
//	printf("%p\n", &Person::Print);
//	p.Print();
//	printf("%p\n", &Student::Print);
//	s.Print();
//	printf("%p\n", &Teacher::Print);
//	t.Print();
//
//	return 0;
//}

////继承出子类，有隐藏/重定义
//#include <iostream>
//#include <string>
//using namespace std;
//class Person//父类  
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//	string _name = "peter";//姓名
//	int _age = 18;//年龄 
//};
//
//class Student : public Person
//{
//public:
//	void Print()//隐藏了父类函数，但是父类函数依旧存在这个类中
//	{
//		cout << "Student::void Print()" << endl;
//	}
//	string _name = "limou";//隐藏了父类变量，但是父类变量依旧存在这个类中
//};
//class Teacher : public Person
//{
//public:
//	void Print()//隐藏了父类函数，但是父类函数依旧存在这个类中
//	{
//		cout << "Teacher::void Print()" << endl;
//	}
//	string _name = "dimou";//隐藏了父类变量，但是父类变量依旧存在这个类中
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	Teacher t;
//
//	printf("%p\n", &Person::_name);
//	//在创建类的对象之前，类的成员变量不会拥有任何有效的内存地址，这些地址尚未分配
//	//当你尝试打印类内的成员变量地址时，如果类的对象尚未被创建，那么这些成员变量的地址有可能将是nullptr
//	//因此不能这么打印变量的地址，除非是静态成员变量
//	
//	cout << endl << "打印成员变量地址:" << endl;
//	printf("%s, %p\n", p._name.c_str(), &p._name);
//	printf("%s, %p\n", s._name.c_str(), &s._name);
//	printf("%s, %p\n", t._name.c_str(), &t._name);
//	
//	cout << endl << "打印成员函数地址:" << endl;
//	printf("%p\n", &Person::Print);
//	p.Print();
//	printf("%p\n", &Student::Print);
//	s.Print();
//	printf("%p\n", &Teacher::Print);
//	t.Print();
//
//	return 0;
//}