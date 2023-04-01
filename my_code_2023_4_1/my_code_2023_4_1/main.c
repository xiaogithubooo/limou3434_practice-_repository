#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest&&src);
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = "xxxxxxxxxx";
//	char arr2[] = "abcd";
//	char* a = (char*)my_memcpy(arr1, arr2, 3);
//	printf("%s", a);
//	return 0;
//}
void* my_memmove(void* dest, const void* src, size_t num)
{
    void* ret = dest;
    assert(dest && src);
    if (dest < src)
    {
        while (num--)
        {
            *(char*)dest = *(char*)src;
            dest = (char*)dest + 1;
            src = (char*)src + 1;
        }
    }
    else
    {
        while (num--)
        {
            *((char*)dest + num) = *((char*)src + num);
        }
    }
    return ret;
}
int main()
{
    char arr1[20] = "abcdfgh";
    printf("%s", (char*)my_memmove(arr1+2, arr1, 2));
	return 0;
}