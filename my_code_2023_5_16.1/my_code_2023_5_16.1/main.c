#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

< code1
int main()
{
#ifndef __CPP
#error 你还没有定义__CPP
#endif
	return 0;
}
< code2
int main()
{
	printf("\n%s %d\n", __FILE__, __LINE__);
#line 60 "test.h"
	printf("\n%s %d\n", __FILE__, __LINE__);
	printf("\n%s %d\n", __FILE__, __LINE__);
	printf("\n%s %d\n", __FILE__, __LINE__);
	return 0;
}
< code3
int main()
{
#define M 10
#ifdef M
#pragma message("M被定义过了")
#endif
	return 0;
}
< code4
int main()
{
#define STR(X) #X
	printf("PI:"STR(3.1415926)"\n");
	return 0;
}
< code5
#define TOSTRING(S) #S
int main()
{
	char str[64] = TOSTRING(1000000);
	printf("%s", str);
	return 0;
}
< code6
#define NUMBER(n) number##n 
int main()
{
	int NUMBER(1) = 100; 
	int NUMBER(2) = 1000;
	int NUMBER(3) = 10000;
	printf("%d\n", NUMBER(1));
	printf("%d\n", NUMBER(2));
	printf("%d\n", NUMBER(3));
	return 0;
}