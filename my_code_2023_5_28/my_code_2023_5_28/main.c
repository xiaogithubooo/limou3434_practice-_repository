#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
int MyAdd(int a, int b)
{
	int c = 0;
	c = a + b;
	return c;
}
int main()
{
	int x = 0xA;
	int y = 0xB;
	int z = MyAdd(x, y);
	printf("z %x\n", z);
	return 0;
}
//int main()
//{
//	int arr1[3] = { 1, 2, 3 };
//	int arr2[4] = { 0, 0, 0, 0 };
//	int* p1 = arr1 + 1;
//	int* p2 = arr2 + 2;
//	printf("%zd", p2 - p1);//编译器不会报警！这种结果是不可预知的
//	return 0;
//}

//int main() {
//    int a = 5, b;
//    __asm {
//        mov eax, a
//        add eax, 10
//        mov b, eax
//    }
//    printf("%d", b);
//    return 0;
//}
