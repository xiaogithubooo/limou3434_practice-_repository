#define _CRT_SECURE_NO_WARNINGS 1
//使用例子
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//    int* a = (int*)malloc(sizeof(int));
//    if (a == NULL)
//    {
//        printf("申请失败\n");
//        printf("%s\n", strerror(errno));
//        exit(-1);//或者return 1;
//    }
//    *a = 5;
//    printf("在%p地址处存储了数值:%d\n", a, *a);
//    free(a);//释放动态内存
//    a = NULL;//置空，避免野指针的出现
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define NUMBER 10
//int main()
//{
//    //1.申请动态内存
//    int* arr = (int*)malloc(sizeof(int) * NUMBER);
//    if (arr == NULL)//对返回值指针进行检查
//    {
//        printf("申请失败\n");
//        printf("%s\n", strerror(errno));
//        exit(-1);//或者return 1;
//    }
//
//    //2.使用动态内存
//    for (int i = 0; i < NUMBER; i++)
//    {
//        arr[i] = i + 1;
//    }
//
//    for (int i = 0; i < NUMBER; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//
//    //3.释放动态内存
//    free(arr);//释放动态内存
//    arr = NULL;//置空，避免野指针的出现
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define NUMBER 10
//int main()
//{
//    //1.申请动态内存
//    int* arr = (int*)calloc(1, NUMBER * sizeof(int));
//    if (arr == NULL)//对返回值指针进行检查
//    {
//        printf("申请失败\n");
//        printf("%s\n", strerror(errno));
//        exit(-1);//或者return 1;
//    }
//
//    //2.使用动态内存
//    for (int i = 0; i < NUMBER; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//
//    //3.释放动态内存
//    free(arr);//释放动态内存
//    arr = NULL;//置空，避免野指针的出现
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define NUMBER 10
//int main()
//{
//    //1.申请动态内存
//    int* arr = (int*)malloc(NUMBER * sizeof(int));//注意参数设计有点不太一样
//    if (arr == NULL)//对返回值指针进行检查
//    {
//        printf("申请失败\n");
//        printf("%s\n", strerror(errno));
//        exit(-1);//或者return 1;
//    }
//
//    //2.使用动态内存
//    //①输入数据
//    for (int i = 0; i < NUMBER; i++)
//    {
//        arr[i] = i * i;
//    }
//    //②打印数据
//    for (int i = 0; i < NUMBER; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    //3.再次扩大动态内存
//    int* arr1 = realloc(arr, sizeof(int) * (NUMBER + 10));
//    if (arr1 == NULL)//对返回值指针进行检查
//    {
//        printf("申请失败\n");
//        printf("%s\n", strerror(errno));
//        exit(-1);//或者return 1;
//    }
//
//    //4.使用扩大后的动态内存
//    //①查看原数据是否还存在
//    for (int i = 0; i < NUMBER; i++)
//    {
//        printf("%d ", arr1[i]);
//    }
//    //②查看是否可以在新申请的空间赋予新的数据
//    for (int i = NUMBER; i < NUMBER + 10; i++)
//    {
//        arr1[i] = i * i;
//    }
//    printf("\n");
//    for (int i = 0; i < NUMBER + 10; i++)
//    {
//        printf("%d ", arr1[i]);
//    }
//
//    //5.释放动态内存
//    free(arr1);//释放动态内存
//    arr1 = NULL;//置空，避免野指针的出现
//    return 0;
//}
//如果为了代码的变量统一性，也可以这么做
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define NUMBER 10
//int main()
//{
//    //1.申请动态内存
//    int* arr = (int*)malloc(NUMBER * sizeof(int));//注意参数设计有点不太一样
//    if (arr == NULL)//对返回值指针进行检查
//    {
//        printf("申请失败\n");
//        printf("%s\n", strerror(errno));
//        exit(-1);//或者return 1;
//    }
//
//    //2.使用动态内存
//    //①输入数据
//    for (int i = 0; i < NUMBER; i++)
//    {
//        arr[i] = i * i;
//    }
//    //②打印数据
//    for (int i = 0; i < NUMBER; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    //3.再次扩大动态内存
//    int* arr1 = realloc(arr, sizeof(int) * (NUMBER + 10));
//    if (arr1 == NULL)//对返回值指针进行检查
//    {
//        printf("申请失败\n");
//        printf("%s\n", strerror(errno));
//        exit(-1);//或者return 1;
//    }
//    else 
//    {
//        arr = arr1;//这样后面的代码就会统一一些
//    }
//
//    //4.使用扩大后的动态内存
//    for (int i = NUMBER; i < NUMBER + 10; i++)
//    {
//        arr[i] = i * i;
//    }
//    printf("\n");
//
//    for (int i = 0; i < NUMBER + 10; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//
//    //5.释放动态内存
//    free(arr1);//释放动态内存
//    arr1 = NULL;//置空，避免野指针的出现
//    return 0;
//}
//#include <stdlib.h>
//void test()
//{
//    int i = 0;
//    int* p = (int*)malloc(10 * sizeof(int));
//    if (NULL == p)
//    {
//        return 1;
//    }
//    for (i = 0; i <= 10; i++)
//    {
//        *(p + i) = i;//当i等于10的时候就发生越界访问
//    }
//    free(p);
//}
//int main()
//{
//    test();
//    return 0;
//}
//#include <stdlib.h> 
//void test()
//{
//    int a = 10;
//    int* p = &a;
//    free(p);//释放了非动态内存
//}
//int main()
//{
//    test();
//}
//#include <stdlib.h>
//void test()
//{
//    int* p = (int*)malloc(100);
//    p++;
//    free(p);//p不再指向动态内存的起始位置
//}
//int main()
//{
//    test();
//    return 0;
//}
//#include <stdlib.h>
//#include <windows.h>
////int main()
////{
////    while (1)
////    {
////        int* p = (int*)malloc(100);
////        Sleep(100);
////    }
////}
//int main()
//{
//	int* a;
//	*a = 10;
//	return 0;
//}
