#include <iostream>
#include <string>
using namespace std;
//1.父类Person
class Person
{
public:
    Person(string name, int age) : _name(name), _age(age)//不是默认的构造函数
    {
        cout << "Person(string nume, int age) : _name(\"peter\"), _age(18)" << endl;
    }
    ~Person()
    {
        cout << "~Person()" << endl;
    }
    Person(Person& p)//不是默认的拷贝构造函数
    {
        cout << "Person(Person& p)" << endl;
        _name = p._name;
        _age = p._age;
    }
    Person& operator=(const Person& p)//不是默认的赋值重载函数
    {
        cout << "Person operator=(const Person& p)" << endl;
        if (this != &p)
        {
            _name = p._name;
            _age = p._age;
        }
        return *this;
    }
    void Print()
    {
        cout << "Print()" << endl;
        cout << "name:" << _name << " age:" << _age << endl;
    }
protected:
    string _name;
    int _age;
};

//2.子类Student
class Student : public Person
{
public:
    Student(string name, int age, int stuid = 00000000) : Person(name, age), _stuid(stuid)//这里调用显示调用父类的构造函数（并且没有明确指定父类成员，只是简写了父类成员变量的名字），初始化子类中从父类继承过来的成员，然后才初始化子类自己的成员
    {
        cout << "Student(string name, int age, int stuid = 00000000) : Person(name, age), _stuid(stuid)" << endl;
    }
    ~Student()
    {
        cout << "~Student()" << endl;
        //无需自己调用父类函数的析构函数，编译器会自己帮助我们调用
    }
    Student(Student& s) : Person(s), _stuid(s._stuid)//这里使用了切片显式调用父类的拷贝构造函数（可以选择不指定父类），初学者推荐一直显式调用，有助于代码理解和可读性。
    {
        cout << "Student(Student& s) : Person(s), _stuid(s._stuid)" << endl;
    }
    Student& operator=(const Student& p)
    {
        cout << "Student& operator=(const Student& p)" << endl;
        if (this != &p)
        {
            Person::operator=(p);
            _stuid = p._stuid;
        }
        return *this;
    }
    void Print()//构成成员函数隐藏了
    {
        //Print();//这就变成自己调用自己了，此时就不可以不明确父类了
        Person::Print();//指明父类
        cout << "stuid:" << _stuid << endl;
    }
protected:
    int _stuid;
};
int main()
{
    Student s1("limou", 18, 22130800);
    Student s2(s1);
    Student s3("daimou", 22, 22109988);
    s1 = s3;

    s1.Print();
    s2.Print();
    s3.Print();
    return 0;
}

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