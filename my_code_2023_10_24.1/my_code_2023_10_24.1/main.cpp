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
	int _f_number = 1;
};

class Mother
{
public:
	virtual void Function_1()
	{
		cout << "Mother:Function_1()" << endl;
	}
	virtual void Function_2()
	{
		cout << "Mother:Function_2()" << endl;
	}
private:
	int _m_number = 2;
};
class Son : public Father, public Mother
{
public:
	virtual void Function_1()
	{
		cout << "Son:Function_1()" << endl;
	}
	virtual void Function_3()//����麯�������ڵ�һ���������
	{
		cout << "Son:Function_3()" << endl;
	}

private:
	int _s_number = 3;
};

typedef void(*VFUNC)();
void PrintVFT(VFUNC arr[])//��ӡ�麯�����ڵĺ���
{
	for (size_t i = 0; arr[i] != 0; i++)//�����Ǹ���VS�����⴦��ſ�����ôдֹͣѭ���������ģ�������������ֻ���Լ�д�̶���ѭ������
	{
		printf("[%d]:%p->", i, arr[i]);
		arr[i]();//���ú���
	}
	printf("\n");
}

int main()
{
	Son s;
	VFUNC* table1 = (VFUNC*)( *(int*)&s );//��һ�����
	//VFUNC* table2 = (VFUNC*)( *( (int*)( (char*)&s + sizeof(Father))));//�ڶ������ֱ��ʹ��ָ�������
	Mother* ptr = &s;
	VFUNC* table2 = (VFUNC*)( *( (int*)ptr ) );//�ڶ����������������Ƭ��ָ��ƫ�ƣ�
	PrintVFT(table1);
	PrintVFT(table2); 
	return 0;
}


//#include <iostream>
//using namespace std;
//
//class Father
//{
//public:
//	virtual void Function_1()
//	{
//		cout << "Father:Function_1()" << endl;
//	}
//	virtual void Function_2()
//	{
//		cout << "Father:Function_2()" << endl;
//	}
//private:
//	int _b_number = 1;
//};
//class Son : public Father
//{
//public:
//	virtual void Function_1()
//	{
//		cout << "Son:Function_1()" << endl;
//	}
//	virtual void Function_3()
//	{
//		cout << "Son:Function_3()" << endl;
//	}
//	virtual void Function_4()
//	{
//		cout << "Son:Function_4()" << endl;
//	}
//	void Function_5()
//	{
//		cout << "Son:Function_5()" << endl;
//	}
//private:
//	int _d_number = 2;
//};
//class Grandson : public Son
//{
//public:
//	virtual void Function_3()
//	{
//		cout << "Grandson:Function_3()" << endl;
//	}
//};
//void Function(Father* f)
//{
//	f->Function_1();
//}
//
//void test_1()
//{
//	Father f;
//	Son s;
//	Grandson g;
//
//	static int a = 0;
//	int b = 0;
//	int* p1 = new int;
//	const char* p2 = "hello";
//
//	printf("��̬����%p\n", &a);
//	printf("ջ����%p\n", &b);
//	printf("������%p\n", p1);
//	printf("�����/����������%p\n", p2);
//	printf("����ַ��%p\n", *((int*)(&s)));
//
//	printf("Father::Function_1 �麯����ַ��%p\n", &Father::Function_1);//��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
//	printf("Father::Function_2 �麯����ַ��%p\n", &Father::Function_2);//��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
//	printf("Son::Function_1 �麯����ַ��%p\n", &Son::Function_1);//��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
//	printf("Son::Function_2 �麯����ַ��%p\n", &Son::Function_2);//��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
//	printf("Son::Function_3 �麯����ַ��%p\n", &Son::Function_3);//��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
//	printf("Son::Function_4 �麯����ַ��%p\n", &Son::Function_4);//��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
//	printf("Grandson::Function_1 �麯����ַ��%p\n", &Grandson::Function_1);//��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
//	printf("Grandson::Function_2 �麯����ַ��%p\n", &Grandson::Function_2);//��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
//	printf("Grandson::Function_3 �麯����ַ��%p\n", &Grandson::Function_3);//��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
//	printf("Grandson::Function_4 �麯����ַ��%p\n", &Grandson::Function_4);//��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
//
//	printf("��ͨ������ַ��%p\n", Function);
//	//ע�⣺��Ա����������һ���﷨�涨������ֻʹ�ú��������������ȡ��ַ
//	//ע�⣺������ʹ�� bTest.Function_1 ���ַ�ʽ��ӡ�麯����ַ����Ϊ������ַû�б��洢�ڶ�����
//}
//
//typedef void(*VFUNC)();
//void PrintVFT(VFUNC arr[])//��ӡ�麯�����ڵĺ���
//{
//	for (size_t i = 0; arr[i] != 0; i++)//�����Ǹ���VS�����⴦��ſ�����ôдֹͣѭ���������ģ�������������ֻ���Լ�д�̶���ѭ������
//	{
//		printf("[%d]:%p->", i, arr[i]);
//		arr[i]();//���ú���
//	}
//	printf("\n");
//}
//void test_2()
//{
//	Father f;
//	VFUNC* vPtrT1 = (VFUNC*)(*(int*)&f);//�麯�����ַ
//	PrintVFT(vPtrT1);
//
//	Son s;
//	VFUNC* vPtrT2 = (VFUNC*)(*(int*)&s);//�麯�����ַ
//	PrintVFT(vPtrT2);
//
//	Grandson g;
//	VFUNC* vPtrT3 = (VFUNC*)(*(int*)&g);//�麯�����ַ
//	PrintVFT(vPtrT3);
//}
//int main()
//{
//	test_1();
//	test_2();
//	return 0;
//}
////64λ������п��ܲ�һ�������黻��32λƽ̨