#define _CRT_SECURE_NO_WARNINGS 1
#include "Data.h"
void TestData1(void)
{
	Data d1(2022, 7, 24);
	d1.Print();
	Data d2(d1);
	d2.Print();

	Data d3(2022, 8, 24);
	Data d4(2023, 6, 21);
	d4 = d1 = d3;//�������Ҫ�õ���ֵ��������غ����������ǿ������캯��������ע��������������ֵ

	d3.Print();
	d1.Print();
	d4.Print();

	d2 = d2;//����ʹ�õ����Լ����Լ���ֵ����ֵ��������ؿ��Կ����������Ż�
	d2.Print();
}
void TestData2(void)
{
	Data d5(2000, 1, 1);
	Data d6(d5);
	Data d7(1900, 1, 2);
	Data d8(3000, 5, 4);
	if (d5 == d6)
	{
		if (d5 != d7)
		{
			if (d5 > d7)
			{
				if (d5 < d8)
				{
					cout << "�ɹ���" << endl;
				}
			}
		}
	}
}
void TestData3(void)
{
	Data d9(2001, 10, 28);
	d9.Print();
	d9 += 20;
	d9.Print();
	(d9 + 3).Print();
	Data d10 = d9 + 4;
	d10.Print();
	(++d10).Print();//Data operator++(&d10);//ǰ��++
	(d10++).Print();//Data operator++(&d10, 0);//����++�����ﴫ0������ʵ��ʲôֵ����Ҫ��ֻҪ�������������־���
	d10.Print();
}
void TestData4(void)
{
	;
}
int main()
{
	//TestData1();
	//TestData2();
	//TestData3();
	TestData4();
	return 0;
}