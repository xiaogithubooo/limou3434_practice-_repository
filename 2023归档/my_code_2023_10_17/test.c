#include <stdio.h>
#include <stdlib.h>
int g_value_2;
int g_value_1 = 10;
int main(int argc, char* argv[], char* env[])
{
    printf("code addr<代码区/正文>: %p\n\n", main);
    const char* str = "hello word!";
    /*
        注意“hello word!”是存储在正文代码区域（说），实际上所有的字面常量都是硬编码进代码的
        而代码是只读的，不可以被修改的        
        而str变量的空间开辟在栈上，
        但是str这个指针变量保存的是处于静态数据区内的“hello word!”里'h'的地址，
        故打印str就是打印静态数据区的地址
    */

    printf("read only addr<静态区>: %p\n\n", str);

    printf("init g_value_1 global addr<已初始化全局变量区>: %p\n\n", &g_value_1);//static变量也会放在这里，您可以自己试一下在这里加上一个static变量（这也就是为什么static变量只会初始化一次的原因）

    printf("uninit g_value_2 global addr<未初始化全局变量区>: %p\n\n", &g_value_2);

    int* p1 = (int*)malloc(sizeof(int) * 10);
    int* p2 = (int*)malloc(sizeof(int) * 10);
    printf("heap addr<堆区>: %p\n", p1);
    printf("heap addr<堆区>: %p\n\n", p2);

    printf("stack addr<栈区>: %p\n", &str);
    printf("stack addr<栈区>: %p\n", &p1);
    printf("stack addr<栈区>: %p\n\n", &p2);

    for (int i = 0; i < argc; i++)
    {
        printf("command line paramete<命令行参数>r：argv[%d] = %p\n", i, argv[i]);
    }
    printf("\n");
    for (int j = 0; env[j]; j++)
    {
        printf("command line parameter<环境变量>：env[%d] = %p\n", j, env[j]);
    }

    free(p1);
    free(p2);
    return 0;
}
