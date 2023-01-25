#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//²âÊÔÈı¸ö´úÂë
int main()
{
	char arr[] = "abcd";
	char arr_1[] = { 'a', 'b', 'c', 'd' };
	printf("%d %d", strlen(arr), strlen(arr_1));
	return 0;
}
int main()
{
    char arr[] = "abcd";
    char arr_1[] = { 'a', 'b', 'c', 'd' };
    printf("%zd %zd", sizeof(arr), sizeof(arr_1));
    return 0;
}
int main()
{
    char arr[] = "abcd";
    char arr_1[] = { 'a', 'b', 'c', 'd' };
    printf("%s %s", arr, arr_1);
    return 0;
}