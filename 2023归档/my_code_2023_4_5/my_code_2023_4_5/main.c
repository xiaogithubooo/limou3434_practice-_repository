#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()
{
    char arr1[100] = { 0 };
    char arr2[100] = { 0 };
    gets(arr1);
    gets(arr2);
    int i = 0;
    while (arr1[i])
    {
        if (0 == strchr(arr2, arr1[i]))
        {
            printf("%c", arr1[i]);
        }
        i++;
    }
    return 0;
}

int is_exist(char* str, char ch)
{
	while (*str)
	{
		if (*str == ch)
		{
			return 1;
		}
		str++;
	}
	return 0;
}
int main()
{
	char arr1[100] = { 0 };
	char arr2[100] = { 0 };
	gets(arr1);
	gets(arr2);
	int i = 0;
	while (arr1[i])
	{
		if (0 == is_exist(arr2, arr1[i]))
		{
			printf("%c", arr1[i]);
		}
		i++;
	}
	return 0;
}

#include <stdio.h>
int main()
{
	int number = 0;
	char nums[10 + 3 + 1] = { 0 };
	int i = 0;
	int k = 0;
	int size_num = scanf("%d", &number);
	while (number)
	{
		if (k % 3 == 0 && k != 0)
		{
			nums[i] = ',';
			i++;
		}

		nums[i] = (number % 10) + '0';
		i++;
		k++;

		number /= 10;
	}
	int j = 0;
	for(j = 13; j >= 0; j--)//跳过数组后面的0
	{
		if (nums[j] != 0)
		{
			break;
		}
	}
	for (j; j >= 0; j--)
	{
		printf("%c", nums[j]);
	}
	return 0;
}

int main()
{
	int a = -3;
	//1000 0000|0000 0000|0000 0011(原码)
	//1111 1111|1111 1111|1111 1101(补码)

	unsigned int b = 2;
	//0000 0000|0000 0000|0000 0010(原/补码)

	long c = a + b;
	//  1111 1111|1111 1111|1111 1101
	// +0000 0000|0000 0000|0000 0010
	// -------------------------------
	//  1111 1111|1111 1111|1111 1111(补码)
	//  1111 1111|1111 1111|1111 1110(反码)
	//  1000 0000|0000 0000|0000 0001(原码)
	printf("%ld", c);
	//打印结果为-1
	return 0;
}


int main()
{
	unsigned char i = 7;
	int j = 0;
	for (; i > 0; i -= 3)
	{
		++j;
	}
	printf("%d\n", j);
	return 0;
}