#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <errno.h>
int main()
{
	//���ļ�
	FILE* fpRead= fopen("limou_test.txt", "r");
	if (fpRead == NULL)
	{
		perror("fopen_fpRead_����");
		return 1;
	}
	FILE* fpWrite = fopen("limou_test_copy.txt", "w");
	if (fpWrite == NULL)
	{
		fclose(fpRead);//����ڶ����ļ�������������������ý���һ���ļ�Ҳ����
		fpRead = NULL;
		perror("fopen_fpWrite_����");
		return 1;
	}
	//�����ļ�
	int ch = 0;
	while ((ch = fgetc(fpRead)) != EOF)
	{
		fputc(ch, fpWrite);
	}
	if (feof(fpRead))
	{
		printf("�����ļ�ĩβ�ˣ�\n");
	}
	else if (ferror(fpWrite))
	{
		printf("������ȡ�������⣡\n");
	}
	printf("�����ɹ�\n");
	//�ر��ļ�
	fclose(fpRead);
	fclose(fpWrite);
	fpRead = NULL;
	fpWrite = NULL;
	return 0;
}

#define NUM 10
#include <stdio.h>
int main()
{
	int arr[NUM] = { 2,2,4,4,1,1,6,6,5,7 };
	for (int i = 0; i < NUM - 1; i++)
	{
		for (int j = 0; j < NUM - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < NUM; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

#define NUM 10
#include <stdio.h>
int main()
{
	int arr[NUM] = { 2,2,4,4,1,1,6,6,5,7 };
	int a = 0;
	for (int i = 0; i < NUM; i++)
	{
		 a^= arr[i];//�������Ԫ�ص����
	}
	//���з���
	int k = 1;
	int t = 0;
	while (a)
	{
		if (a & k == 1)
		{
			break;
		}
		else
		{
			a >>= 1;
			t++;
		}
	}
	int arr1 = 0;
	int arr2 = 0;
	for (int i = 0; i < NUM; i++)
	{
		if (k & (arr[i] >> t) == 1)
		{
			arr1 ^= arr[i];
		}
		else
		{
			arr2 ^= arr[i];
		}
	}
	printf("�ҵ����������ǣ�%d %d\n", arr1, arr2);
	return 0;
}

#define NUM 10
#include <stdio.h>
void function(int arr[], int num)
{
	1�������еĵط��������һ��
	int ret = 0;
	int i = 0;//ѭ����
	for (i = 0; i < num; i++)
	{
		ret ^= arr[i];
	}
	2����������һλ��1���������ݣ�
	int pos = 0;
	for (i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}
	3���������
	int x1 = 0, x2 = 0;
	for (i = 0; i < num; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			x1 ^= arr[i];
		}
		else
		{
			x2 ^= arr[i];
		}
	}
	printf("%d %d", x1, x2);
}
int main()
{
	int arr[NUM] = { 2,2,4,4,1,1,6,6,5,7 };
	function(arr, NUM);
	return 0;
}