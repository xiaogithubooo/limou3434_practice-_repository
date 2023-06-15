#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>//引入C++库
using namespace std;//引入std命名空间
#define MAXSIZE 50
typedef int KeyType;
typedef struct
{
	KeyType key;
}ElemType;
typedef struct
{
	ElemType* R;//动态数组
	int length;//数组长度
}SSTable;
void Create(SSTable& T)
{
	int i;
	T.R = new ElemType[MAXSIZE + 1];
	cin >> T.length;
	for (i = 1; i <= T.length; i++)
		cin >> T.R[i].key;
}
int Search_Bin(SSTable T, KeyType k);//给一个严格递增数列，用二分查找法查找k在数列中的位置

int main()
{
	SSTable T;//首先定义一个结构体用来指向某个要被查找的数组R，其大小是length
	KeyType k;//要查找的数k
	Create(T);//初始化结构体T：成员R指向51个大小为ElemType的动态空间，并且输入能够使用的大小n
	cin >> k;//输入要查找的数
	int pos = Search_Bin(T, k);//pos存储函数返回值，其值是数字k在中数列的相对位置，若返回0则说明没有找到
	if (pos == 0) 
		cout << "NOT FOUND" << endl;
	else
		cout << pos << endl;
	return 0;
}

int Search_Bin(SSTable T, KeyType k)
{
	int left = 1;
	int right = T.length;
	int mean = (left + right) >> 1;
	while (left < right)
	{
		if (k > T.R[mean].key)
		{
			left = mean + 1;
		}
		else if (k < T.R[mean].key)
		{
			right = mean - 1;
		}
		else
		{
			return mean;
		}
		mean = (left + right) >> 1;
	}
	return 0;
}

