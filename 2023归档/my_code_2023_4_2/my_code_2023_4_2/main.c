#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define OFFSETOF(st_type, mem_name) (size_t)&(((st_type*)0)->mem_name)

//#define OFFSETOF(st_type, mem_name) (size_t)( st_type s = { 0 }, &(s.a) - &(s.mem_name) )
//                                    (size_t)( struct S s = { 0 }, &(s.a) - &(s.b) )
//Ц���ˣ���������������д����hhhhhhh

typedef struct S
{
	char a;//ƫ����Ϊ0
	int b;//ƫ����Ϊ4
	double c;//ƫ����Ϊ8
}S;
int main()
{
	printf("%zd\n", OFFSETOF(struct S, b));	
	printf("%zd\n", OFFSETOF(struct S, a));
	printf("%zd\n", OFFSETOF(struct S, c));
	return 0;
}