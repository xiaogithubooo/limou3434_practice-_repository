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

class D : public C, public B//��̳У����������μ̳�
{
public:
    D(const char* s1, const char* s2, const char* s3, const char* s4)
        : B(s1, s2), C(s1, s3)//, A(s1)//����û����̳��˾Ͳ�����ʹ�����һ�����캯����
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
//class D : public B, public C//��̳У���������̳�
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
//class A//����A
//{
//public:
//    int _a;
//};
//
//class B : public A//����B
//{
//public:
//    int _b;
//};
//
//class C : public A//����C
//{
//public:
//    int _c;
//};
//
//class D : public B, public C//��̳к��������D
//{
//public:
//    int _d;
//};
//
//int main()
//{
//    D d;
//
//    //1.��ֵ��_a���������ڲ����˶����ԣ���ֵʧ��
//    //d._a = 0;
//
//    //2.ʹ��::ָ������_a����ǿ����˶����ԣ����ǳ������������ࣨ������_a�̳��Բ�ͬ�ĸ��ࣩ
//    d.B::_a = 1;
//    d.C::_a = 2;
//    cout << d.B::_a << " " << d.C::_a << endl;
//
//    //3.����û�ж��������⣬��˲���Ҫʹ��::
//    d._b = 3;//����d.B::_b = 3;
//    d._c = 4;//����d.C::_c = 4;
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
//class D : public C, public B//��̳У���������̳�
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
//    Person per;//�������
//
//    //1.����������ø���
//    //Student& rstu = per;//������
//    //Student& rstu = (Student)per;//������
//
//    //2.����ָ��ָ����
//    //Student* pstu = &per;//������
//    Student* pstu = (Student*)&per;//��Ȼ����ͨ�������Ǻ�Σ�գ��п��ܻ�Խ��
//
//    //3.���ֲ��������Ժ��л����������ۣ����漰�� dynamic_cast ��ʹ�ã�
//    Student std;
//    Person* pper = &std;
//    Student* pstd = (Student*)pper;//����
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
//	//1.��������
//	int a1 = 1;
//	int a2 = 10;
//	a2 = a1;//û����ʱ�����������ǱȽ���Ȼ��Ȼ��
//	int& a3 = a2;//�ɹ�
//
//	int b1 = 100;
//	double b2 = 3.14;
//	b2 = b1;//����ʱ��������
//	//double& b3 = b1;//ʧ��
//	const double& b3 = b1;//�ɹ�
//
//	//2.�Զ�������
//	Father n1(1);
//	Child n2(2, 3);
//	n1 = n2;//�����棬���ǳɹ���ֻ�ǽ������еĳ�Ա�������������ࣩ
//	Father n3 = n2;//�����棬���ǳɹ���ֻ�ǽ������еĳ�Ա�������������ࣩ
//	Father& n4 = n2;//�ɹ�
//	Father* n5 = &n2;//�ɹ�
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class A//����A
//{
//public:
//    int _a;
//};
//
//class B : virtual public A//����B
//{
//public:
//    int _b;
//};
//
//class C : virtual public A//����C
//{
//public:
//    int _c;
//};
//
//class D : public B, public C//��̳к��������D
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
//    cout << d.B::_a << " " << d.C::_a << endl;//����˶����Ժ���������
//
//    d._b = 3;//����d.B::_b = 3;
//    d._c = 4;//����d.C::_c = 4;
//    cout << d._b << " " << d._c << endl;
//
//    d._d = 5;
//    return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class A//����A
//{
//public:
//    int _a;
//};
//
//class B : public A//����B
//{
//public:
//    int _b;
//};
//
//class C : public A//����C
//{
//public:
//    int _c;
//};
//
//class D : public B, public C//��̳к��������D
//{
//public:
//    int _d;
//};
//
//int main()
//{
//    D d;
//
//    //1.��ֵ��_a���������ڲ����˶����ԣ���ֵʧ��
//    //d._a = 0;
//
//    //2.ʹ��::ָ������_a����ǿ����˶����ԣ����ǳ������������ࣨ������_a�̳��Բ�ͬ�ĸ��ࣩ
//    d.B::_a = 1;
//    d.C::_a = 2;
//    cout << d.B::_a << " " << d.C::_a << endl;
//
//    //3.����û�ж��������⣬��˲���Ҫʹ��::
//    d._b = 3;//����d.B::_b = 3;
//    d._c = 4;//����d.C::_c = 4;
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
//	//���ڳ�Ա����
//	string _name;
//	int _age;
//};
//
//class Student : public Person
//{
//public:
//	Student() : Person(), _stuid(22103) { cout << "Student()" << endl; };
//
//	//���ڳ�Ա����
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
//	//���ڳ�Ա����
//	//Person::string _name;
//	//Person::int _age;
//	int _jobid;
//};
//class Graduate : public Student, public Teacher//��̳�
//{
//public:
//	//���ڳ�Ա����
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
//	//cout << g._name << endl;//����ʧ�ܣ����ж����ԣ����ﵽ����Student��Ļ���Teacher���_name��
//	cout << g.Student::_name << endl;//���гɹ����ɹ����������
//	cout << g.Teacher::_name << endl;//���гɹ����ɹ����������
//	
//	//����һ����������������֣������ô��
//	//���仰˵��������������ֶΣ����硰���֤�������Ķ���ID�����ܴ������ݰɣ�
//	//Ҳ����˵�����μ̳з������������࣡
//	
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
////1.����Person
//class Person
//{
//public:
//    Person(string name, int age) : _name(name), _age(age)//����Ĭ�ϵĹ��캯��
//    {
//        cout << "Person(string nume, int age) : _name(\"peter\"), _age(18)" << endl;
//    }
//    ~Person()
//    {
//        cout << "~Person()" << endl;
//    }
//    Person(Person& p)//����Ĭ�ϵĿ������캯��
//    {
//        cout << "Person(Person& p)" << endl;
//        _name = p._name;
//        _age = p._age;
//    }
//    Person& operator=(const Person& p)//����Ĭ�ϵĸ�ֵ���غ���
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
////2.����Student
//class Student : public Person
//{
//public:
//    Student(string name, int age, int stuid = 00000000) : Person(name, age), _stuid(stuid)//���������ʾ���ø���Ĺ��캯��������û����ȷָ�������Ա��ֻ�Ǽ�д�˸����Ա���������֣�����ʼ�������дӸ���̳й����ĳ�Ա��Ȼ��ų�ʼ�������Լ��ĳ�Ա
//    {
//        cout << "Student(string name, int age, int stuid = 00000000) : Person(name, age), _stuid(stuid)" << endl;
//    }
//    ~Student()
//    {
//        cout << "~Student()" << endl;
//        //�����Լ����ø��ຯ�����������������������Լ��������ǵ���
//    }
//    Student(Student& s) : Person(s), _stuid(s._stuid)//����ʹ������Ƭ��ʽ���ø���Ŀ������캯��������ѡ��ָ�����ࣩ����ѧ���Ƽ�һֱ��ʽ���ã������ڴ������Ϳɶ��ԡ�
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
//    void Print()//���ɳ�Ա����������
//    {
//        //Print();//��ͱ���Լ������Լ��ˣ���ʱ�Ͳ����Բ���ȷ������
//        Person::Print();//ָ������
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
//class Person//����  
//{
//public:
//	Person() : _name("Person"), _age(18) { cout << "Person() : _name(\"Person\"), _age(18)" << endl; }
//	void Print()
//	{
//		cout << "Person::void Print()" << endl;
//		cout << "Person::name:" << _name << endl;
//		cout << "Person::age:" << _age << endl << endl;
//	}
//	string _name;//����
//	int _age;//���� 
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
//	string _name;//����
//	int _age;//���� 
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

////�����̳г������࣬û������/�ض���
//#include <iostream>
//#include <string>
//using namespace std;
//class Person//����  
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//	string _name = "peter";//����
//	int _age = 18;//���� 
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
//	//�ڴ�����Ķ���֮ǰ����ĳ�Ա��������ӵ���κ���Ч���ڴ��ַ����Щ��ַ��δ����
//	//���㳢�Դ�ӡ���ڵĳ�Ա������ַʱ�������Ķ�����δ����������ô��Щ��Ա�����ĵ�ַ�п��ܽ���nullptr
//	//��˲�����ô��ӡ�����ĵ�ַ�������Ǿ�̬��Ա����
//
//	cout << endl << "��ӡ��Ա������ַ:" << endl;
//	printf("%s, %p\n", p._name.c_str(), &p._name);
//	printf("%s, %p\n", s._name.c_str(), &s._name);
//	printf("%s, %p\n", t._name.c_str(), &t._name);
//
//	cout << endl << "��ӡ��Ա������ַ:" << endl;
//	printf("%p\n", &Person::Print);
//	p.Print();
//	printf("%p\n", &Student::Print);
//	s.Print();
//	printf("%p\n", &Teacher::Print);
//	t.Print();
//
//	return 0;
//}

////�̳г����࣬������/�ض���
//#include <iostream>
//#include <string>
//using namespace std;
//class Person//����  
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//	string _name = "peter";//����
//	int _age = 18;//���� 
//};
//
//class Student : public Person
//{
//public:
//	void Print()//�����˸��ຯ�������Ǹ��ຯ�����ɴ����������
//	{
//		cout << "Student::void Print()" << endl;
//	}
//	string _name = "limou";//�����˸�����������Ǹ���������ɴ����������
//};
//class Teacher : public Person
//{
//public:
//	void Print()//�����˸��ຯ�������Ǹ��ຯ�����ɴ����������
//	{
//		cout << "Teacher::void Print()" << endl;
//	}
//	string _name = "dimou";//�����˸�����������Ǹ���������ɴ����������
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	Teacher t;
//
//	printf("%p\n", &Person::_name);
//	//�ڴ�����Ķ���֮ǰ����ĳ�Ա��������ӵ���κ���Ч���ڴ��ַ����Щ��ַ��δ����
//	//���㳢�Դ�ӡ���ڵĳ�Ա������ַʱ�������Ķ�����δ����������ô��Щ��Ա�����ĵ�ַ�п��ܽ���nullptr
//	//��˲�����ô��ӡ�����ĵ�ַ�������Ǿ�̬��Ա����
//	
//	cout << endl << "��ӡ��Ա������ַ:" << endl;
//	printf("%s, %p\n", p._name.c_str(), &p._name);
//	printf("%s, %p\n", s._name.c_str(), &s._name);
//	printf("%s, %p\n", t._name.c_str(), &t._name);
//	
//	cout << endl << "��ӡ��Ա������ַ:" << endl;
//	printf("%p\n", &Person::Print);
//	p.Print();
//	printf("%p\n", &Student::Print);
//	s.Print();
//	printf("%p\n", &Teacher::Print);
//	t.Print();
//
//	return 0;
//}