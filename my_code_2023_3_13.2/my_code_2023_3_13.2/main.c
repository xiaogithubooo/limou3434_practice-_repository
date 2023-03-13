#define _CRT_SECURE_NO_WARNINGS 1
//��־
//1��ʹ��strtok
//2��ʹ��memcpy
//3��ģ��ʵ��memcpy
//4��ģ��ʵ��memmove
//5������ʹ��memset

#include <stdio.h>
#include <string.h>
//1��ʹ��strtok
/*д��һ*/
int main()
{
    char arr[] = "limou@3434.com";//ע������ط�ֻ��ʹ������
    char buf[30] = { 0 };
    strcpy(buf, arr);

    const char* p = "@.";

    char* str = strtok(buf, p);
    printf("%s\n", str);

    str = strtok(NULL, p);
    printf("%s\n", str);

    str = strtok(NULL, p);
    printf("%s\n", str);
    return 0;
}
/*д����*/
int main()
{
    char arr[] = "limou@3434.com";//ע������ط�ֻ��ʹ������
    char buf[30] = { 0 };
    strcpy(buf, arr);

    const char* p = "@.";
    char* str = NULL;
    for (str = strtok(buf, p); str != NULL; str = strtok(NULL, p))
    {
        printf("%s\n", str);
    }
    return 0;
}
//2��ʹ��memcpy
struct {
	char name[40];
	int age;
} person, person_copy;
int main()
{
	char myname[] = "Pierre de Fermat";

	memcpy(person.name, myname, strlen(myname) + 1);
	person.age = 46;

	memcpy(&person_copy, &person, sizeof(person));
	printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);
	return 0;
}
//3��ģ��ʵ��memcpy
#include <assert.h>
void* my_memcpy(void* dest, const void* src, size_t num)//ע��void*�ǲ��ܽ��н����úͼӼ�������
{
	void* ret;
	assert(dest && src);
		while (num--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	return ret;
}
//4��ģ��ʵ��memmove
void my_memmove(void* dest, const void* src, size_t num)
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
//5������ʹ��memset
int main()
{
    char arr[10] = "bcdef";
    memset(arr, 'x', 4);
    printf("%s", arr);
}