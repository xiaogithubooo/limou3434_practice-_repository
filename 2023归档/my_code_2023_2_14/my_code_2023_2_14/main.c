#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//1���洢����ʵ��
//2��rand������ģ��
//3�������к�������
//4��������ҵ�������
//�ٵ�������ʹ����ȫ����λ��ż��ǰ��
//��ģ��ʵ�������⺯��strlen��strcpy����
//5�����ݴ洢�Ĳ���
//6������charȡֵ����


//1���洢����ʵ��
int main()
{
	int i = 30;
	while (i++ < 33)
	{
		int i = 100;
		printf("%d ", i);
	}
	return 0;
}
int main()
{
	register int number = 100;
	int* p = &number;
	printf("%p", p);
	return 0;
}
//2��rand������ģ��
static unsigned long int next = 1;//����
unsigned int rand0(void)
{
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768;
}
int main()
{
	printf("%d\n", rand0());
	printf("%d\n", rand0());
	printf("%d\n", rand0());
	printf("%d\n", rand0());
	printf("%d\n", rand0());
	printf("%d\n", rand0());
	printf("%d\n", rand0());
	return 0;
}
//3�������к�������
#include<stdlib.h>
int main(int argc, char *argv[])
{
	int ch;
	FILE* fp;
	unsigned long count = 0;
	if (argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("Can't open %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("File %s has %lu characters\n", argv[1], count);

	return 0;
}
//4��������ҵ�������
//�ٵ�������ʹ����ȫ����λ��ż��ǰ��
void function(int* arr, int*arrx, int number)
{
	int i = 0, j = number - 1;

	for (int x = 0; x < number; x++)
	{
		if (arr[x] % 2 == 1)//����
		{
			arrx[i] = arr[x];
			i++;
		}
		else
		{
			arrx[j] = arr[x];
			j--;
		}
	}
}
int main()
{
	int arr[100] = { 0 };
	int arrx[100] = { 0 };
	int number = 0;
	scanf("%d", &number);
	for (int i = 0; i < number; i++)
	{
		scanf("%d", &arr[i]);
	}
	function(arr, arrx, number);
	for (int i = 0; i < number; i++)
	{
		printf("%d ", arrx[i]);
	}
	return 0;
}
//��ģ��ʵ�������⺯��strlen��strcpy����
#include <stdio.h>
#include <assert.h>
int my_strlen(const char* str)
{
	int count = 0;
	assert(str);//assert(str != NULL);//���Ե�ʹ��
	while(*str)//while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	int len = my_strlen("abcdef");
	printf("%d\n", len);
	return 0;
}
void my_strcpy(char* dest, char* src)
{
    //���ԣ����߸ĳ�assert(dest && src)
    assert(dest != NULL);
    assert(src != NULL);
    while (*dest++ = *src++)
    {
        ;
    }
}
int main()
{
    char arr1[100] = "abcdefn";
    char arr2[100] = { 0 };
    my_strcpy(arr2, arr1);
    printf("%s", arr2);
    return 0;
}
//5�����ݴ洢�Ĳ���
int main()
{
	int a = 100;
	return 0;
}�����С��
int check_sys(void)
{
	int i = 1;
	return (*((char*)&i));
}
int check_sys_x()
{
	union
	{
		int i;
		char c;
	}un;
	un.i = 1;
	return un.c;
}
int main()
{
	//int ret = check_sys();
	int ret = check_sys_x();
	if (ret == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	return 0;
}
int main()
{
	unsigned char c = -1;
	printf("%d", c);
	return 0;
}
//6������charȡֵ
#include <stdio.h>
int main()
{
    char a = -128;
    printf("%u\n", a);
    return 0;
}
#include <stdio.h>
int main()
{
    char a = 128;
    printf("%u\n", a);
    return 0;
}