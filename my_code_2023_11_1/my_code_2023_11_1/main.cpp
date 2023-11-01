#include <iostream>
#include <string>
using namespace std;
//1.����Person
class Person
{
public:
    Person(string name, int age) : _name(name), _age(age)//����Ĭ�ϵĹ��캯��
    {
        cout << "Person(string nume, int age) : _name(\"peter\"), _age(18)" << endl;
    }
    ~Person()
    {
        cout << "~Person()" << endl;
    }
    Person(Person& p)//����Ĭ�ϵĿ������캯��
    {
        cout << "Person(Person& p)" << endl;
        _name = p._name;
        _age = p._age;
    }
    Person& operator=(const Person& p)//����Ĭ�ϵĸ�ֵ���غ���
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

//2.����Student
class Student : public Person
{
public:
    Student(string name, int age, int stuid = 00000000) : Person(name, age), _stuid(stuid)//���������ʾ���ø���Ĺ��캯��������û����ȷָ�������Ա��ֻ�Ǽ�д�˸����Ա���������֣�����ʼ�������дӸ���̳й����ĳ�Ա��Ȼ��ų�ʼ�������Լ��ĳ�Ա
    {
        cout << "Student(string name, int age, int stuid = 00000000) : Person(name, age), _stuid(stuid)" << endl;
    }
    ~Student()
    {
        cout << "~Student()" << endl;
        //�����Լ����ø��ຯ�����������������������Լ��������ǵ���
    }
    Student(Student& s) : Person(s), _stuid(s._stuid)//����ʹ������Ƭ��ʽ���ø���Ŀ������캯��������ѡ��ָ�����ࣩ����ѧ���Ƽ�һֱ��ʽ���ã������ڴ������Ϳɶ��ԡ�
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
    void Print()//���ɳ�Ա����������
    {
        //Print();//��ͱ���Լ������Լ��ˣ���ʱ�Ͳ����Բ���ȷ������
        Person::Print();//ָ������
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