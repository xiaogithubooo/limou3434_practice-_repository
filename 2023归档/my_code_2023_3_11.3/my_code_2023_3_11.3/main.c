#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
//日志
//1、size_t容易出错的地方
//2、计时器实现strlen函数
//3、递归实现strlen
//4、实现strcpy
//5、实现strcat
//6、实现strcmp
//7、测试str系列代码
//8、暴力（BF算法）实现strstr

//1、size_t容易出错的地方
int main()
{
    char* str1 = "abcdef";
    char* str2 = "bbb";
    printf("%u\n", 3 - 6);
    if (strlen(str2) - strlen(str1) > 0)
    {
        printf("%u\n", strlen(str2) - strlen(str1));
        printf("str2 > str1\n");//输出“>”，本质原因是size_t是一个无符号整型
    }
    else
    {
        printf("srt1 > str2\n");
    }
    return 0;
}
//2、计时器实现strlen函数
int my_strlen(const char* str)
{
    int count = 0;    assert(str);//防止空指针危险
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}
//3、递归实现strlen
#include <assert.h>
int my_strlen_2(const char* str)
{
    if (*str != '\0')
    {
        return (1 + my_strlen_2(str + 1));
    }
    else
    {
        return 0;
    }
}
//4、实现strcpy
#include <assert.h>
char* my_strcpy(char* dest, const char* src)
{
    char* ret = dest;
    assert(dest && src);//保证指针的有效性
    while (*dest++ = *src++);//利用'\0'可以停下
    return ret;
}
//5、实现strcat
#include <assert.h>
char* my_strcat_1(char* dest, const char* src)
{
    assert(dest && src);
    char* ret = dest;
    while (*dest != '\0')
    {
        dest++;
    }
    while (*dest++ = *src++);
    return ret;
}
//但是没有办法自己给自己追加，因为'\0'被改了，找到开始覆盖的位置，却遗失了结束的位置，并且陷入死循环当中
//注意，const只是不能改src指向的字符串，但是另外一个指向同一串字符串的指针若是没有const修饰，依旧可以通过改指针修改字符串
//6、实现strcmp
int my_strcmp(const char* str1, const char* str2)
{
    assert(str1 && str2);    
    while (*str1 == *str2)
    {
        if (*str1 > *str2)
        {
            return 0;
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;
    /*
        if(*str1 > *str2)
        {
            return 1;
        }
        else
        {
            return 0;9mm 
        }
    */
}
//7、测试str系列代码
int main()
{
	char arr1[20] = "hello \0xxxxxxxxx";
	char arr2[] = "word";
	strncpy(arr1, arr2, 6);
	return 0;
}
//8、暴力（BF算法）实现strstr
char* my_strstr(const char* str1, const char* str2)
{
    char* s1 = NULL;
    char* s2 = NULL;
    char* cp = (char*)str1;//由于str1被const修饰，所以这里加上强制类型转化可以消除警告

    while (*cp)
    {
        s1 = cp;
        s2 = (char*)str2;//由于str2被const修饰，所以这里加上强制类型转化可以消除警告
        while (*s1 && *s2 && *s1 == *s2)//有一个字符串遇到'\0'都可以不用循环了
        {
            s1++;
            s2++;
        }
        cp++;
        if (*s2 == '\0')
        {
            return cp;
        }
    }
    return NULL;//没找到
}