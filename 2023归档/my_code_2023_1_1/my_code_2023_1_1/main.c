#define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
//1��scanf��������������о�
//int main()
//{
//	float x = 0.0;
//	scanf("%.2f", &x);//���ִ����Ǵ���ģ�������λ����
//	printf("%f", x);
//	return 0;
//}

//2��ţ����һ���򵥵���Ŀ��KIKI����ĩ�ɼ���
//int main()
//{
//    float a, b, c, d;
//    scanf("%f %f %f %f", &a, &b, &c, &d);
//    printf("%.1f", (a * 0.2) + (b * 0.1) + (c * 0.2) + (d * 0.5));
//
//    return 0;
//}

//3��ţ������Ŀ��KIKI����߷֡�
//int a, b, c;
//int t = 0;
//int main()
//{
//    scanf("%d %d %d", &a, &b, &c);
//    if (a > b)
//    {
//        t = a;
//        if (t > c)
//        {
//            printf("%d", t);
//        }
//        else
//        {
//            printf("%d", c);
//        }
//    }
//    else
//    {
//        t = b;
//        if (t > c)
//        {
//            printf("%d", t);
//        }
//        else
//        {
//            printf("%d", c);
//        }
//    }
//    return 0;
//}

//4��ţ������Ŀ�������塱�жϺ���
//int my_judge(char t, char(*arr)[3])//ע������Ķ�ά���鴫�Σ�������д��char* a������д�Ǵ���ģ�Ӧ�ø�ϰ��ά����Ĵ���
//{
//
//	//�ж���Ӯ***************************************************************
//	int i = 0;//ѭ����
//	for (i = 0; i < 3; i++)//Ӯ�ں�����
//	{
//		if (  (arr[i][0] == arr[i][1]) && (arr[i][0] == arr[i][2]) && (arr[i][0]==t)  )
//		{
//			return 1;
//		}
//	}
//	for (i = 0; i < 3; i++)//Ӯ��������
//	{
//		if (  (arr[0][i] == arr[1][i]) && (arr[0][i] == arr[2][i]) && (arr[0][i] == t)  )
//		{
//			return 1;
//		}
//	}
//	if (  (arr[0][0] == arr[1][1]) && (arr[0][0] == arr[2][2]) && (arr[0][0] == t)  )//Ӯ����б����
//	{
//		return 1;
//	}
//	else if (   (arr[0][2] == arr[1][1]) && (arr[0][2] ==arr[2][0]) && (arr[0][2] == t)  )//Ӯ����б����
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}//Ӯ�˷���1�����˷���0
//
//
//int main()
//{
//	int x = 0;//�������������
//	int y = 0;//�������������
//	char arr[3][3] = { '0' };//����һ������
//	for (x = 0; x < 3; x++)//�������ݹ���
//	{
//		for (y = 0; y < 3; y++)
//		{
//			scanf("%c", &(arr[x][y]));
//			getchar();//��������ҲҪע��һ��
//		}
//	}
//
//	int K = my_judge('K',arr);//�洢���
//	int B = my_judge('B',arr);//�洢���
//
//	if (K == B)//��Ӯ��1�����߶��䣨0��
//	{
//		printf("No winner!\n");
//	}
//	else if (K > B)
//	{
//		printf("KiKi wins!\n");
//	}
//	else if (K < B)
//	{
//		printf("BoBo wins!\n");
//	}
//
//	return 0;
//}

//5��һ���������������Ϊscanf�������ո�
//int main()
//{
//	char a = 0;
//	scanf("%c", &a);
//	printf("%d", a);
//	//���Կ����������32�����ǿո��ASCII��ֵ
//	//����˵�����ַ������пո��ǿ��Ա������
//}

//6��KiKi�������������
//typedef struct TDate
//{
//    int Month;
//    int Day;
//    int Year;
//}TDate;
//
//
//int main()
//{
//    TDate x;
//    x.Month = 0;
//    x.Day = 0;
//    x.Year = 0;
//    scanf("%d %d %d", &x.Year, &x.Month, &x.Day);
//    printf("%d/%d/%d", x.Day, x.Month, x.Year);
//    return 0;
//}

//7�������������
//int main()
//{
//    int n = 0, m = 0;
//    int t = 0;
//    scanf("%d %d", &n, &m);
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            scanf("%d ", &t);
//            printf("%d ", t);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//8��ͳ�Ƴɼ�
//int main()
//{
//    int n = 0;
//    double t = 0;
//    double max = 0;
//    double min = 100.0;
//    double add = 0;
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%lf", &t);
//        max = max > t ? max : t;
//        min = min < t ? min : t;
//        add += t;
//    }
//    printf("%.2lf %.2lf %.2lf", max, min, add / n);
//}