#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//1、验证是否可以使用变长数组
int main()
{
	int n = 10;
	scanf("%d", &n);
	int arr[n];
	return 0;
}//可惜了，VS2022不能使用
//2、尝试使用宏来注释
#define a /
int main()
{
	int b = 1;
	printf("%d", b);
	return 0;
}//不行hhhhhhhh
//3、小乐乐查找数字
int main()
{
	int n = 0;
	int arr[100] = { 0 };
	int number = 0;
	int i = 0, j = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &number);
	for (i = 0; i < n; i++)
	{
		if (arr[i] == number)
		{
			j++;
		}
	}
	printf("%d\n", j);
	return 0;
}
//4、密码验证
int main()
{
	char arr[100];
	char arr1[100];
	scanf("%s %s", arr, arr1);
	if (strcmp(arr, arr1) == 0)
	{
		printf("same\n");
	}
	else
	{
		printf("different\n");
	}
	return 0;
}
//5、KiKi学程序设计基础
int main()
{
	printf("printf(\"Hello world!\\n\");\n");
	printf("cout << \"Hello world!\" << endl;\n");
	return 0;
}
//6、小乐乐定闹钟
int main()
{
	int h = 0, m = 0, number = 0;
	int i = 0;
	scanf("%d:%d %d", &h, &m, &number);
	while (number >= 60)
	{
		number -= 60;
		i++;
	}
	h = h + i;
	m = m + number;
	while (h >= 24)
	{
		h -= 24;
	}
	while (m >= 60)
	{
		m -= 60;
		h++;
	}
	printf("%02d:%02d\n", h, m);
	return 0;
}
//7、小乐乐求和
int main()
{
    long n = 0;
    scanf("%ld", &n);
    long sum = 0;
    for (long i = 1; i <= n; i++)
    {
        sum += i;
    }
    printf("%ld\n", sum);
    return 0;
}