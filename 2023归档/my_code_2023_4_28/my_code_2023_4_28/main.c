#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    int number1 = 0;
    int number2 = 0;
    scanf("%d:%d", &number1, &number2);
    int flag = 0;

    if (number1 > 12)
    {
        number1 = number1 - 12;
        flag = 1;
    }
    else if (number1 == 12)
    {
        flag = 1;
    }

    if (flag == 0)
    {
        printf("%d:%d AM", number1, number2);
    }
    else
    {
        printf("%d:%d PM", number1, number2);
    }
    return 0;
}

int main()
{
    int number = 0;
    int num = 0;
    int number1 = 0, number2 = 0;
    scanf("%d", &number);
    scanf("%d", &num);
    number1 = number / 100;
    number2 = number % 100;
    number = number1 * 60 + number2 + num;
    printf("%d", number / 60);
    if (number % 60 <= 9)
        printf("0");
    printf("%d", number % 60);
    return 0;
}

typedef int(*type)(void);
type show(void)
{
	printf("hello word!\n");
	return show;
}
int main()
{
	int(*pf)(void) = show();
	pf();
	return 0;
}