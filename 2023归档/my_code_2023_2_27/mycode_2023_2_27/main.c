#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
//1����ϰģ��ʵ��strlen����
int my_strlen(const char* str)//��ϣ���ı��ַ���������������const
{
    int count = 0;
    assert(str);//����ʹ��assert(str != NULL)�������Ƕ��Ե�ʹ�ã������������ÿ�ָ��
    while (*str)//��while (*str != '\0')
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
//2����ϰģ��ʵ��strcpy����
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