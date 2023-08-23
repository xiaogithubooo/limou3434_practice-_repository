#include <iostream>
#include <vector>
#include <list>
using namespace std;
void test_1()
{
		vector<int>array;
		array.push_back(100);
		array.push_back(300);
		array.push_back(300);
		array.push_back(300);
		array.push_back(300);
		array.push_back(500);
		//100 300 300 500

		vector<int>::iterator itor;
		for (itor = array.begin(); itor != array.end(); itor++)
		{
			if (*itor == 300)
			{
				itor = array.erase(itor);
			}
		}
		for (itor = array.begin(); itor != array.end(); itor++)

		{
			cout << *itor << " ";
		}
}
void test_2()
{
	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(ar) / sizeof(int);//�õ�10
	vector<int> v(ar, ar + n);

	cout << v.size() << ":" << v.capacity() << endl;
	//���10 : 10

	v.reserve(100);
	v.resize(20);
	cout << v.size() << ":" << v.capacity() << endl;
	//���20 : 100

	v.reserve(50);
	v.resize(5);
	cout << v.size() << ":" << v.capacity() << endl;
	//���5 : 100
}
void test_3()
{
	int ar[] = { 1,2,3,4,0,5,6,7,8,9 };
	int n = sizeof(ar) / sizeof(int);//��9
	vector<int> v(ar, ar + n);

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it != 0)//1 2 3 4 |5 6 7 8 9
			cout << *it;
		else
			v.erase(it);
		it++;
	}
}
void test_4()
{
	//���������
	int ar[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n = sizeof(ar) / sizeof(int);//�õ�10
	list<int> mylist(ar, ar + n);

	//����5���Ԫ�أ�����ָ��5�ĵ�����
	list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);

	reverse(mylist.begin(), pos);//->4, 3, 2, 1, 0, 5, 6, 7, 8, 9
	reverse(pos, mylist.end());//->4, 3, 2, 1, 0, 9, 8, 7, 6, 5
	list<int>::const_reverse_iterator crit = mylist.crbegin();
	while (crit != mylist.crend())
	{
		cout << *crit << " ";
		++crit;
	}
	cout << endl;//5,6,7,8,9,0,1,2,3,4
}

template<typename T>
void removeDuplicates(list<T> &aList)
{
	T curValue;
	typename list<T>::iterator cur, p;
	cur = aList.begin();
	while (cur != aList.end())
	{
		curValue = *cur;
		p = ++cur;
		while (p != aList.end())
		{
			if (*p == curValue)
			{
				if (p == cur)//֮����������������Ϊ
				{
					cur = p = aList.erase(p);
				}
				else
				{
					p = aList.erase(p);
				}
			}
			else
			{
				p++;
			}
		}
	}
}
void test_5()
{
	list<int> li;
	li.push_back(1);
	li.push_back(3);
	li.push_back(3);
	li.push_back(3);
	li.push_back(4);
	//1133131444

	removeDuplicates(li);
	list<int>::iterator it = li.begin();
	for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << *it << " ";
	}
}

int main()
{
	//test_1();
	//test_2();
	//test_3();
	//test_4();
	test_5();
	return 0;
}

////void test_1()
////{
////	unsigned int un = 3000;
////	//30 0000 0000�Ķ�������1011 0010 1101 0000 0101 1110 0000 0000
////	//�洢�ķ�ʽ���޷���������˲�����ǣ�1011 0010 1101 0000 0101 1110 0000 0000
////
////	//������з��Ŵ�ӡ���ͻ���Ϊ�Ǹ���
////	//1011 0010 1101 0000 0101 1110 0000 0000�����룩
////	//1011 0010 1101 0000 0101 1101 1111 1111�����룩
////	//1100 1101 0010 1111 1010 0010 0000 0000��ԭ�룩
////	//1001101001011111010001000000000 = -1294967296
////	printf("%u %d", un, un);
////}
////void test_2()
////{
////	//a=97, b=98 ,c=99, d=100
////	//С��
////
////	char a = 'abcd';
////	
////	int b = 'abcd';
////	//������С�����������ֽڴ洢
////	//100 99 98 97
////	//64 63 62 61���պþ����ڴ��е�ֵ
////	//���ȡ�������Ǿ���61 62 63 64
////	//Ҳ����01100001 01100010 01100011 01100100
////	//01100001011000100110001101100100��Ϊint���ʹ�ӡ
////	//�ʴ�ӡ1633837924
////	printf("%c %d", a, b);
////}
////void test_3()
////{
////	printf("Hello\vWorld!\n");//���ַ�����ʹ��\v
////	puts("Hello\vWorld!");//��puts������ʹ��\v
////}
////void test_4()
////{
////	float a = 3.4E38 * 100.0f;
////	printf("%f", a);
////}
////void test_5()
////{
/////*
////NaN �ǡ�IEEE 754����������׼�ж��������ֵ����ʾ�������֡���Not a Number����
////NaN �ڼ�����ͨ�����ڱ�ʾ��Ч��δ����Ĳ���������Լ��������ֵ�����㡣���������������������
////1.������㣺���磬0.0/0.0��
////2.������ȥ��������磬INFINITY - INFINITY��
////3.��Ч���������㣺���磬������ƽ�����������Ķ����ȡ�asin()�������1�Ĳ�����
////4.�� NaN ��Ϊ�����Ĳ�����
////
////NaN ���ص��ǣ�
////1.NaN �������κ�������������������ζ�� NaN == NaN �Ľ��Ϊ false��
////2.�� NaN �����καȽϲ������� <��>��==���Ľ������ false��
////3.�� NaN �����������㣨��ӷ����������˷����������Ľ����Ȼ�� NaN��
////4.�� C �����У�����ʹ�� isnan() ���������һ��ֵ�Ƿ�Ϊ NaN���˺�������һ������ֵ��������ĸ������� NaN�����򷵻� 0��
////*/
////	//double a = 0.0 / 0.0;  //������ΪNaN
////	double b = sqrt(-1.0); //������ΪNaN
////	//if (isnan(a))
////	//{
////	//	printf("a �� NaN\n");
////	//}
////	if (isnan(b))
////	{
////		printf("b �� NaN\n");
////	}
////	//if (a != a)
////	//{
////	//	printf("a ����������\n");
////	//}
////	if (b != b)
////	{
////		printf("b ����������\n");
////	}
////}
//void test_6()
//{
//	printf("abcdef");
//	fflush(stdout);
//}
//int main()
//{
//	//test_1();
//	//test_2();
//	//test_3();
//	//test_4();
//	//test_5();
//	test_6();
//
//	return 0;
//}
///*
//??=include <stdio.h>
//int main()
//??<
//	printf("??(??)");
//	return 0;
//??>
//*/