#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//PTAÌâÄ¿£º×Ö·û´®×óÒÆ£¬https://pintia.cn/problem-sets/14/exam/problems/811
void fun(char* arr, int n)
{
    char* p1 = arr;
    char* p2 = &arr[n - 1];
    while (p1 < p2)
    {
        char temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        p1++;
        p2--;
    }
}
int main()
{
    char arr[1000] = { 0 };
    gets(arr);
    int size = strlen(arr);
    fun(arr, size);
    int k = 0;
    scanf("%d", &k);
    k = k % size;
    fun(arr + size - k, k);
    fun(arr, size - k);
    puts(arr);
    return 0;
}