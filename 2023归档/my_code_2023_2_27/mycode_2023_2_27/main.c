#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
//1、复习模拟实现strlen函数
int my_strlen(const char* str)//不希望改变字符串，所以用上了const
{
    int count = 0;
    assert(str);//或者使用assert(str != NULL)，这里是断言的使用，避免后面解引用空指针
    while (*str)//即while (*str != '\0')
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
//2、复习模拟实现strcpy函数
void my_strcpy(char* dest, char* src)
{
    //断言，或者改成assert(dest && src)
    assert(dest != NULL);
    assert(src != NULL);
    while (*dest++ = *src++)
    {
        ;
    }
}
char* my_strcpy(char* dest, char* src)
{
    assert(dest && src);
    char* ret = dest;
    while (*dest++ = *src++);
    return ret;
}
int main()
{
    char a[] = "abcdef";
    char b[] = "ghijke";
   ;
    printf("%s", my_strcpy(a, b));
    return 0;
}