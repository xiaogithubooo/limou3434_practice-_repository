//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//void _function(int* ptorS, int* pt, int* pT)
//{
//	*pt += 30;//������Ϣ30min
//	if (*pt > *pT)
//	{
//		*ptorS += (*pt - *pT);
//		return;
//	}
//	*ptorS += (30 * 3);
//}
//int main()
//{
//	//1.ʱ����
//	int T = 0;
//	int scanfRet = scanf("%d", &T);
//	int t = 0;
//
//	//2.�����
//	int rabS = 0;
//	int torS = 0;
//
//	//3.��ʱ��
//	while (t != T)//��һmin��ʼ
//	{
//		rabS += 9;
//		torS += 3;
//		t++;
//		//��һmin����
//		if (t % 10 == 0 && t != 0)
//		{
//			_function(&torS, &t, &T);
//		}
//	}
//	if (rabS > torS)
//	{
//		printf("^_^ %d", rabS);
//	}
//	else if (rabS < torS)
//	{
//		printf("@_@ %d", torS);
//	}
//	else
//	{
//		printf("-_-");
//	}
//	return 0;
//}

//#define DE_BUG 1
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//void _function(char* str, int x, int y)
//{
//    while (x < y)
//    {
//        char tmp = str[x];
//        str[x] = str[y];
//        str[y] = tmp;
//        x++;
//        y--;
//    }
//}
//
//int main()
//{
//    //1.���ˣ�Hello World   Here I Come��
//    char* str = (char*)malloc(sizeof(char) * 500000);
//    if (!str) exit(-1);
//    char ch;
//    ch = getchar();
//    while (ch == ' ')
//    {
//        ch = getchar();
//    }
//    int i = 0;
//    for (i = 0; ch != '\n'; i++)//���û���������з���ѭ��
//    {
//        if (ch == ' ')//���chΪ�ո�����������Ŀո�
//        {
//            str[i] = ch;//����һ���ո�
//
//            ch = getchar();
//            while (ch == ' ')
//            {
//                ch = getchar();
//            }
//        }
//        else
//        {
//            str[i] = ch;
//            ch = getchar();
//        }
//    }
//    str[i] = '\0';
//    if (str[i - 1] == ' ')
//    {
//        str[i - 1] = '\0';
//    }
//
//    //2.��ת��Come I Here World Hello��
//    int begin = 0;
//    int end = (int)strlen(str) - 1;
//    while (begin < end)
//    {
//        char tmp = str[begin];
//        str[begin] = str[end];
//        str[end] = tmp;
//
//        begin++;
//        end--;
//    }
//#ifndef DE_BUG
//    printf("%s\n", str);
//#endif
//
//
//    //3.�Ӵ���ת��emoC I ereH dlroW olleH\0��
//    int front = 0;
//    int back = 0;
//    while (str[back] != '\0')
//    {
//        if (str[back] == ' ')
//        {
//            _function(str, front, back - 1);//olleH
//            front = back + 1;
//        }
//        back++;
//    }
//    _function(str, front, back - 1);
//    printf("%s\n", str);
//
//    return 0;
//}

#define DE_BUG 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int _fun(int x, int n)//x^N
{
	int add = 1;
	while (n)
	{
		add *= x;
		n--;
	}
	return add;
}

int main()
{
	int A = 0;
	int N = 0;
	scanf("%d %d", &A, &N);
	int n = 1;
	int add = A;
	int a = A;
	while (n < N)
	{
		A += a * _fun(10, n);
		add += A;
		n++;
	}
	printf("%d", add);
	return 0;
}