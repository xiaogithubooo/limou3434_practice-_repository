#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <windows.h>
//1���׳˵ݹ�ĸ�ϰ
int function(int i)
{
	if (i == 1)
	{
		return 1;
	}
	else
	{
		return i * function(i - 1);
	}
}
int main()
{
	int i = 0;
	while(scanf("%d", &i) == 1)
	{
		printf("%d\n", function(i));
	}
	return 0;
}
//2�����ֲ��ҷ�
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//�±�        0,1,2,3,[4],5,6,7,8,9
	int i = 0;
	int k = 0;
	scanf("%d", &k);
	int sz = sizeof(arr) / sizeof(arr[0]);//��������Ĵ�С
	int left = 0;//���±�
	int right = sz - 1;//���±�
	int flag = 0;
	int mid = 0;
	while (left<=right)
	{
		//mid = (left + right) / 2;//�м��±꣨�����е�С���⣬���������������
		mid = left + (right - left) / 2;//�м��±꣨������ƽ��ֵ������õģ���
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			printf("�ҵ��ˣ��±���%d", mid);
			flag = 1;
			break;
		}
	}
	if (0 == flag)
	{
		printf("û���ҵ�\n");
	}
	return 0;
}
//3�������ƶ����м�����
//******************��������⴮�ַ���
//welcome to python!
int main()
{
	char arr1[] = "welcome to python!";
	char arr2[] = "******************";

	int sz = strlen(arr1) - 1;
	int left = 0;
	int right = sz;

	while (left <= right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s", arr2);
		Sleep(500);
		system("cls");//cmd�����ʹ��
		left++;
		right--;
	}
	printf("%s", arr2);
	return 0;
}
//4��goto��ʹ��
int main()
{
	goto a;
	printf("haha\n");
a:
	printf("hehe\n");
	return 0;
}//ֻ���ӡhehe