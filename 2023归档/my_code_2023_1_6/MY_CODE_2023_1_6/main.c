#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//1��С�������ַ���
//���ҵĽⷨ�����Ǻ�ʱ�޴�
int main()
{
	long number = 0;
	char arr[8000] = { 0 };
	scanf("%s", arr);
	long i = 0;//ѭ����
	for (i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == 0)
			break;
		if (arr[i] == 'C')
		{
			for (long a = i; a < strlen(arr); a++)
			{
				if (arr[a] == 0)
					break;
				if (arr[a] == 'H')
				{
					for (long b = a; b < strlen(arr); b++)
					{
						if (arr[b] == 0)
							break;
						if (arr[b] == 'N')
						{
							number++;
						}
					}
				}
			}
		}
	}
	printf("%ld", number);
	return 0;
}
//�ڱ��˵Ľⷨ�����ֽⷨ��ĺã���ȡ�ַ���CHN�ı�Ҫ�����ǻ�ȡ��N��Ȼ�����H�����Ų���C�������ҵ�N���������һ��CHN
int main()
{
	char a[8000];
	gets(a);
	long int c = 0, h = 0, n = 0;

	for (int i = 0; i <= strlen(a); i++)
	{
		if (a[i] == 'C')
		{
			c++;
		}
		else if (a[i] == 'H')
		{
			h += c;
		}
		else if (a[i] == 'N')
		{
			n += h;
		}
	}
	printf("%ld", n);

	return 0;
}

//2������任��û����ȫ���ԣ�ֻ�ܴ����������ʽ��
void f(char t, int x, int y, int(*arr)[10], int n, int m)
{
	int num1 = 0;
	int num2 = 0;
	if (t == 'r')//���б任
	{
		for (int i = 0; i < m; i++)
		{
			num1 = arr[x - 1][i];
			arr[x - 1][i] = arr[y - 1][i];
			arr[y - 1][i] = num1;
		}	
	}
	else if (t == 'c')//���б任
	{
		for (int i = 0; i < n; i++)
		{
			num2 = arr[i][x - 1];
			arr[i][x - 1] = arr[i][y - 1];
			arr[i][y - 1] = num2;
		}
	}
}
int main()
{
	int n = 0, m = 0;//n�к�m��
	int arr[10][10] = { 0 };//�洢����ʽ����
	int k = 0;//�洢��������
	char t = 0;//�洢�����ַ�
	int x = 0, y = 0;//���ڱ��������У��У�

	scanf("%d %d", &n, &m);//�����к���
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
		getchar();//ȥ������
	}
	scanf("%d", &k);
	getchar();//ȥ���ո�
	while (k)
	{
		scanf("%c", &t);
		getchar();//ȥ������
		scanf("%d %d", &x, &y);
		f(t, x, y, arr, n, m);
		k--;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}