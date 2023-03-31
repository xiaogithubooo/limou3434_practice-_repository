//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <assert.h>
//void my_strncpy(char* pstr1, const char* pstr2, size_t size)
//{
//	assert(pstr1 && pstr2);//检查空指针
//	while (size-- && *pstr2)
//	{
//		*pstr1 = *pstr2;
//
//		pstr1++;
//		pstr2++;
//
//	}
//	while (size--)
//	{
//		*pstr1 = '\0';
//		pstr1++;
//	}
//	*pstr1 = '\0';
//}
//int main()
//{
//	char str1[20] = "xxxxxxxxxxxxxx";
//	char str2[20] = "abc";
//	my_strncpy(str1, str2, 8);
//	printf("%s", str1);
//	return 0;
//}
//#include <stdio.h>
//#include <assert.h>
//void my_strncat(char* pstr1, const char* pstr2, size_t size)
//{
//	assert(pstr1, pstr2);
//	while (*pstr1)//遇到str1的'\0'就停下来
//	{
//		pstr1++;
//	}
//	while (size && *pstr2)
//	{
//		*pstr1++ = *pstr2++;
//		size--;
//	}
//	while (size)
//	{
//		*pstr1 = '\0';
//		size--;
//	}
//	*pstr1 = '\0';
//}
//int main()
//{
//	char str1[100] = "xxxxxxxxxxxx";
//	char str2[] = "abcdefghijklmnopqrstuvw";
//	my_strncat(str1, str2, 5);
//	printf("%s", str1);
//	return 0;
//}

