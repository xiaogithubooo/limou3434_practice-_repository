#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
//��־
//1��size_t���׳���ĵط�
//2����ʱ��ʵ��strlen����
//3���ݹ�ʵ��strlen
//4��ʵ��strcpy
//5��ʵ��strcat
//6��ʵ��strcmp
//7������strϵ�д���
//8��������BF�㷨��ʵ��strstr

//1��size_t���׳���ĵط�
int main()
{
    char* str1 = "abcdef";
    char* str2 = "bbb";
    printf("%u\n", 3 - 6);
    if (strlen(str2) - strlen(str1) > 0)
    {
        printf("%u\n", strlen(str2) - strlen(str1));
        printf("str2 > str1\n");//�����>��������ԭ����size_t��һ���޷�������
    }
    else
    {
        printf("srt1 > str2\n");
    }
    return 0;
}
//2����ʱ��ʵ��strlen����
int my_strlen(const char* str)
{
    int count = 0;    assert(str);//��ֹ��ָ��Σ��
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}
//3���ݹ�ʵ��strlen
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
//4��ʵ��strcpy
#include <assert.h>
char* my_strcpy(char* dest, const char* src)
{
    char* ret = dest;
    assert(dest && src);//��ָ֤�����Ч��
    while (*dest++ = *src++);//����'\0'����ͣ��
    return ret;
}
//5��ʵ��strcat
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
//����û�а취�Լ����Լ�׷�ӣ���Ϊ'\0'�����ˣ��ҵ���ʼ���ǵ�λ�ã�ȴ��ʧ�˽�����λ�ã�����������ѭ������
//ע�⣬constֻ�ǲ��ܸ�srcָ����ַ�������������һ��ָ��ͬһ���ַ�����ָ������û��const���Σ����ɿ���ͨ����ָ���޸��ַ���
//6��ʵ��strcmp
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
//7������strϵ�д���
int main()
{
	char arr1[20] = "hello \0xxxxxxxxx";
	char arr2[] = "word";
	strncpy(arr1, arr2, 6);
	return 0;
}
//8��������BF�㷨��ʵ��strstr
char* my_strstr(const char* str1, const char* str2)
{
    char* s1 = NULL;
    char* s2 = NULL;
    char* cp = (char*)str1;//����str1��const���Σ������������ǿ������ת��������������

    while (*cp)
    {
        s1 = cp;
        s2 = (char*)str2;//����str2��const���Σ������������ǿ������ת��������������
        while (*s1 && *s2 && *s1 == *s2)//��һ���ַ�������'\0'�����Բ���ѭ����
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
    return NULL;//û�ҵ�
}