#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define OFFSETOF(st_type, mem_name) (size_t)&(((st_type*)0)->mem_name)

//#define OFFSETOF(st_type, mem_name) (size_t)( st_type s = { 0 }, &(s.a) - &(s.mem_name) )
//                                    (size_t)( struct S s = { 0 }, &(s.a) - &(s.b) )
//笑死了，这个代码真的是我写的吗hhhhhhh

typedef struct S
{
	char a;//偏移量为0
	int b;//偏移量为4
	double c;//偏移量为8
}S;
int main()
{
	printf("%zd\n", OFFSETOF(struct S, b));	
	printf("%zd\n", OFFSETOF(struct S, a));
	printf("%zd\n", OFFSETOF(struct S, c));
	return 0;
}