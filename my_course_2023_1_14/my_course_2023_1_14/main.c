#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1�����ظ�ֵ
int main()
{
	int a, b, c;
	a = b = c = 23;//?!��Ŀ���!?
	printf("%d %d %d\n", a, b, c);
	return 0;
}
//2��sizeof���÷�
int main()
{
	//sizeof�ı�׼д��
	size_t d = sizeof(int);
	printf("%zd", d);

	return 0;
}
//3��const��ʹ��
int main()
{
	int a = 248, b = 4;
	int const* c = 21;
	const int* d = &a;
	int* const e = &b;
	int const* const f = &a;
	
	//*c = 32;
	//*d = 43;
	//e = &a;
	//f = 0x321f;
	return 0;
}
//4����ӡ��������
#include <stdio.h>
int i;
void prt()
{
	for (i = 5; i < 8; i++)
		printf("%c", '*');
	printf("\t");
}
int main()
{
	for (i = 5; i <= 8; i++)
		prt();
	return 0;
}
int main()
{
	int a = 3;
	printf("%d\n", (a += a -= a * a));
	return 0;
}
#include <stdio.h>
int main()
{
    int arr[3][4];
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        int j = 0;
        for (j = 0; j < 4; j++)
        {
            printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
        }
    }
    return 0;
}
int main()
{
	int arr[3] = { 1,2,3 };
	arr[4];
}
//5����ҵ��Ŀ
int main()
{
	int n = 0;
	scanf("%d", &n);

	int num = 0;
	int i = 0;//ͳ�Ƹ�������
	int Add = 0;//������������
	for (int a = 0; a < n; a++)
	{
		scanf("%d", &num);
		if (num < 0)
		{
			i++;
		}
		if (num > 0)
		{
			Add += num;
		}
	}
	printf("%d %d",num)��������
	return 0;
}
//6�������ð������
void function(int arr[])//��������Ԫ�رȽϣ�n������Ҫ�ظ�n-1��ð������
{
    int i = 0;
    int sz = sizeof(arr) / sizeof(arr[0]);//ȷ��ʹ��ð������Ĵ���
    for (i = 0; i < sz - 1; i++)//ѭ��ʹ��ð������
        {
            int j = 0;
            for (j = 0; j < sz - i - 1; j++)//һ��ð������ÿ�������Ͳ��������һ�������ˣ�����-i
            {
                if (arr[j] > arr[j + 1])
                {
                    int num = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = num;
                }
            }
        }
}
int main()
{
    int arr[] = { 3, 4, 1, 6, 8, 9, 6, 8, 9, 7, 0 };
    //����Ϊ����
    function(arr);
    int i = 0;
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}
//7����ȷ��ð������
//��������Ԫ�رȽϣ�n������Ҫ�ظ�n-1��ð������
void function(int* arr, int sz)//ǰ��Ϊ��Ԫ�ص�ַ������������ĸ���
{
    int i = 0;
    for (i = 0; i < sz - 1; i++)//ѭ��ʹ��ð������
    {
        int j = 0;
        for (j = 0; j < sz - i - 1; j++)//һ��ð������ÿ�������Ͳ��������һ�������ˣ�����-i
        {
            if (arr[j] > arr[j + 1])
            {
                int num = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = num;
            }
        }
    }
}
int main()
{
    int arr[] = { 3, 4, 1, 6, 8, 9, 6, 8, 9, 7, 0 };
    //����Ϊ����
    int sz = sizeof(arr) / sizeof(arr[0]);
    function(arr, sz);
    int i = 0;
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}