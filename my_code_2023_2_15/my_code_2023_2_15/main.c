#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
#include <string.h>
#include <stdio.h>
int number = 114514;
int main()
{
	function(2, 3);
	return 0;
}
int main()
{
    char a[1000] = { 0 };
    int i = 0;
    for (i = 0; i < 1000; i++)
    {
        a[i] = -1 - i;
    }
    printf("%d", strlen(a));
    return 0;
}
#include <stdio.h>
long fun(int x) 
{
    if (x == 1 || x == 0)
    {
        return 1;
    }
    return x * fun(x - 1);
}
int main() 
{
    int number = 0;
    int scanf_number = scanf("%d", &number);//��������

    for (int n = 0; n < number; n++) 
    { //"����"һһ��Ӧ"����"
        for (int k = 0; k <= n; k++)
        { //�ݹ�
            printf("%ld ", (fun(n)) / ((fun(k)) * (fun(n - k)))); //�ó�һ����
        }
        printf("\n");
    }
    return 0;
}
int main()
{
    char a[1000] = { 0 };
    int i = 0;
    for (i = 0; i < 1000; i++)
    {
        a[i] = -1 - i;
    }
    printf("%d", strlen(a));
    return 0;
}
#include <stdio.h>

int checkData(int* p)
{
	int tmp[7] = { 0 }; //��Ǳ�ʵ���ǹ�ϣ���˼·��һ��ʼÿ��Ԫ�ض���0��

	int i;
	for (i = 0; i < 5; i++)
	{
		if (tmp[p[i]]) //������λ�õı���Ѿ���1��������ظ���ֱ�ӷ���0��
		{
			return 0;
		}
		tmp[p[i]] = 1; //������ǣ�������λ�ñ��Ϊ1��
	}
	return 1; //ȫ��������Ҳû�г����ظ������������OK��
}

int main()
{
	int p[5]; //0 1 2 3 4�ֱ����a b c d e

	for (p[0] = 1; p[0] <= 5; p[0]++)
	{
		for (p[1] = 1; p[1] <= 5; p[1]++)
		{
			for (p[2] = 1; p[2] <= 5; p[2]++)
			{
				for (p[3] = 1; p[3] <= 5; p[3]++)
				{
					for (p[4] = 1; p[4] <= 5; p[4]++) //���ѭ������
					{
						//����������˵����������ڱȽϱ��ʽֻ��0��1������������Ҫ������������ֻ��һ��Ϊ�棬������ñȽϱ��ʽ��ֵ�ܺ�Ϊ1�ķ�ʽֱ���ж��������˻�Ҫ�ж����ܲ��С�
						if ((p[1] == 2) + (p[0] == 3) == 1 && //B�ڶ����ҵ���
							(p[1] == 2) + (p[4] == 4) == 1 && //�ҵڶ���E����
							(p[2] == 1) + (p[3] == 2) == 1 && //�ҵ�һ��D�ڶ�
							(p[2] == 5) + (p[3] == 3) == 1 && //C����ҵ���
							(p[4] == 4) + (p[0] == 1) == 1 && //�ҵ��ģ�A��һ
							checkData(p) //���ܲ���
							)
						{
							for (int i = 0; i < 5; i++)
							{
								printf("%d ", p[i]);
							}
							putchar('\n');
						}
					}
				}
			}
		}
	}

	return 0;
}
#include<stdio.h>
int main()
{
	int killer = 0;
	//�ֱ����������a,b,c,d,��˭������ʱ����3����˵���滰��һ����˵�˼ٻ�
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
			printf("�����ǣ�%c", killer);
	}
	return 0;
}