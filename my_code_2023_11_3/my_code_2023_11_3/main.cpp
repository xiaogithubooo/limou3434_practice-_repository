//��ӡ�麯�����ַ���麯����ַ���Լ��麯�����ַ�����������ַ�ĶԱ�
#include <iostream>
using namespace std;

class Father
{
public:
	virtual void Function_1()
	{
		cout << "Father:Function_1()" << endl;
	}
	virtual void Function_2()
	{
		cout << "Father:Function_2()" << endl;
	}
private:
	int _b_number = 1;
};

class Son : public Father
{
public:
	virtual void Function_1()
	{
		cout << "Son:Function_1()" << endl;
	}
	virtual void Function_3()
	{
		cout << "Son:Function_3()" << endl;
	}
	virtual void Function_4()
	{
		cout << "Son:Function_4()" << endl;
	}
	void Function_5()
	{
		cout << "Son:Function_5()" << endl;
	}
private:
	int _d_number = 2;
};

class Grandson : public Son
{
public:
	virtual void Function_3()
	{
		cout << "Grandson:Function_3()" << endl;
	}
};

void Function(Father* f)
{
	f->Function_1();
}

void test_1()
{
	Father f;
	Son s;
	Grandson g;

	static int a = 0;
	int b = 0;
	int* p1 = new int;
	const char* p2 = "hello";

	printf("��̬����%p\n", &a);
	printf("ջ����%p\n", &b);
	printf("������%p\n", p1);
	printf("�����/��������%p\n", p2);
	printf("����ַ��%p\n", *((int*)(&s)));

	printf("Father::Function_1 �麯����ַ��%p\n", &Father::Function_1);//��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
	printf("Father::Function_2 �麯����ַ��%p\n", &Father::Function_2);//��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
	printf("Son::Function_1 �麯����ַ��%p\n", &Son::Function_1);//��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
	printf("Son::Function_2 �麯����ַ��%p\n", &Son::Function_2);//��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
	printf("Son::Function_3 �麯����ַ��%p\n", &Son::Function_3);//��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
	printf("Son::Function_4 �麯����ַ��%p\n", &Son::Function_4);//��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
	printf("Grandson::Function_1 �麯����ַ��%p\n", &Grandson::Function_1);//��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
	printf("Grandson::Function_2 �麯����ַ��%p\n", &Grandson::Function_2);//��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
	printf("Grandson::Function_3 �麯����ַ��%p\n", &Grandson::Function_3);//��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
	printf("Grandson::Function_4 �麯����ַ��%p\n", &Grandson::Function_4);//��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ

	printf("��ͨ������ַ��%p\n\n", Function);
	//ע�⣺��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
	//ע�⣺������ʹ�� bTest.Function_1 ���ַ�ʽ��ӡ�麯����ַ����Ϊ������ַû�б��洢�ڶ�����
}

typedef void(*VFUNC)();
void PrintVFT(VFUNC arr[])//�����麯����ָ�룬���Ҵ�ӡ�麯�����ڵĺ�����ַ���ݣ�Ȼ����е���
{
	for (size_t i = 0; arr[i] != 0; i++)//�����Ǹ��� VS �����⴦��ſ�����ôдֹͣѭ���������ģ�������������ֻ���Լ�д�̶���ѭ������
	{
		printf("_vfptr[%d]:%p->", i, arr[i]);
		arr[i]();//���ú���
	}
	printf("\n");
}
void test_2()
{
	Father f;
	VFUNC* vPtrT1 = (VFUNC*)(*(int*)&f);//�麯�����ַ������� 64 λ���Ը� (int*) Ϊ (long long*)
	PrintVFT(vPtrT1);

	Son s;
	VFUNC* vPtrT2 = (VFUNC*)(*(int*)&s);//�麯�����ַ������� 64 λ���Ը� (int*) Ϊ (long long*)
	PrintVFT(vPtrT2);

	Grandson g;
	VFUNC* vPtrT3 = (VFUNC*)(*(int*)&g);//�麯�����ַ������� 64 λ���Ը� (int*) Ϊ (long long*)
	PrintVFT(vPtrT3);
}

int main()
{
	//64λ������᲻һ������Ϊָ�볤�ȱ���� 8 �ֽڣ������黻��32λƽ̨������

	test_1();
	test_2();
	return 0;
}

//#include <iostream>
//using namespace std;
//
//class Base
//{
//public:
//	virtual void Function_1();//������������
//	virtual void Function_2();//���������ȶ���
//private:
//	int _b_number = 1;
//};
//
//class Derive : public Base
//{
//	virtual void Function_1()
//	{
//		cout << "Derive:Function_1()" << endl;
//	}
//private:
//	int _d_number = 2;
//};
//
//void Base::Function_2()
//{
//	cout << "Base:Function_2()" << endl;
//}
//void Base::Function_1()
//{
//	cout << "Base:Function_1()" << endl;
//}
//
//void Function(Base* b)
//{
//	b->Function_1();
//}
//
//int main()
//{
//	Base b;
//	Derive d;
//
//	Function(&b);
//	Function(&d);
//	return 0;
//}
//
//////���صĶ�̬
////#include <iostream>
////using namespace std;
////class A
////{
////public:
////	virtual void func(int val = 1)
////	{
////		cout << "A->" << val << endl;
////	}
////	virtual void test()
////	{
////		func();
////	}
////};
////class B : public A
////{
////public:
////	void func(int val = 0)//����/�ض�����func
////	{
////		cout << "B->" << val << endl;
////	}
////	//�̳��� virtual void test(A* const this)����˼̳е�ʵ���ǿ���ʹ�ø���ĺ����������������һ��������������
////};
////int main()
////{
////	B* p = new B;
////	p->test();
////	//���� B ���ڵ� test()�����ڼ̳е�ʵ���ǿ���ʹ�ø���ĺ�����
////	//���ʵ����ʹ���˸��ຯ����� test()��ȫдΪ void test(A* const this)
////	//���� this ָ����� p ָ�룬ʹ�� this->func() ����ɶ�̬���ã��Ǹ���ָ��ĵ��ã���
////	//����ڲ����õ�������� func()
////	
////	//���麯���ļ̳�ʵ�����Ǽ̳����˸��ຯ���Ľӿڣ�Ȼ����д��ʵ�֣�
////	//��������ڵ�ȱʡֵ�õ��Ǹ����ȱʡֵ�����ࣩ
////
////	p->func();//�����û�й��ɶ�̬�ˣ����������������Ա����
////	return 0;
////}