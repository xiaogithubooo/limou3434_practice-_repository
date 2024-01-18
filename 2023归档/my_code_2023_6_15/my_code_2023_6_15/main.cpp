#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>//����C++��
using namespace std;//����std�����ռ�
#define MAXSIZE 50
typedef int KeyType;
typedef struct
{
	KeyType key;
}ElemType;
typedef struct
{
	ElemType* R;//��̬����
	int length;//���鳤��
}SSTable;
void Create(SSTable& T)
{
	int i;
	T.R = new ElemType[MAXSIZE + 1];
	cin >> T.length;
	for (i = 1; i <= T.length; i++)
		cin >> T.R[i].key;
}
int Search_Bin(SSTable T, KeyType k);//��һ���ϸ�������У��ö��ֲ��ҷ�����k�������е�λ��

int main()
{
	SSTable T;//���ȶ���һ���ṹ������ָ��ĳ��Ҫ�����ҵ�����R�����С��length
	KeyType k;//Ҫ���ҵ���k
	Create(T);//��ʼ���ṹ��T����ԱRָ��51����СΪElemType�Ķ�̬�ռ䣬���������ܹ�ʹ�õĴ�Сn
	cin >> k;//����Ҫ���ҵ���
	int pos = Search_Bin(T, k);//pos�洢��������ֵ����ֵ������k�������е����λ�ã�������0��˵��û���ҵ�
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

