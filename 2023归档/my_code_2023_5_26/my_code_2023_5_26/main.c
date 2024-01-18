#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
typedef int HPDataType;
//向下调整算法
void AdjustDown(HPDataType* arr, int arrsize, int parenti)
{
    int childi = parenti * 2 + 1;
    while (childi < arrsize)
    {
        //1.修正孩子坐标
        if (childi + 1 < arrsize && arr[childi] < arr[childi + 1])
        {
            childi++;
        }
        //2.判断是否需要交换
        if (arr[childi] > arr[parenti])
        {
            int tmp = arr[childi];
            arr[childi] = arr[parenti];
            arr[parenti] = tmp;
            parenti = childi;
            childi = parenti * 2 + 1;

        }
        else
        {
            break;
        }
    }
}
//模拟大量数据存储在文件中
void _make(void)
{
    //造数据
    int n = 10000;//控制数据个数
    int m = 10000;//控制数据范围
    int x = 0;//存储数据本身
    srand((unsigned)time(0));//随机数种子
    const char* file = "data.txt";//定义文件名字
    FILE* fin = fopen(file, "w");//以只写的方式打开该文件，如果该文件不存在就自动创建，存在则覆盖原有的内容
    if (fin == NULL)//打开失败就提示错误
    {
        perror("fopen error");
        return;
    }
    for (size_t i = 0; i < n; ++i)//不断写入n个随机数据
    {
        x = rand() % m;
        fprintf(fin, "%d\n", x);
    }
    fclose(fin);//关闭该文件
}
//模拟针对大量数据的Top-k的堆排
void HeapSort_Topk(int k)
{
    //1.打开文件
    const char* file = "data.txt";
    FILE* fout = fopen(file, "r");
    if (fout == NULL)//打开失败就提示
    {
        perror("fopen error");
        return;
    }
    //2.先只读取k个数据
    HPDataType* kmaxheap = (HPDataType*)malloc(sizeof(HPDataType) * k);//开辟对应大堆的空间
    if (kmaxheap == NULL)//开辟失败就提示
    {
        perror("malloc error");
        return;
    }
    for (int i = 0; i < k; i++)
    {
        int fscanfreturn = fscanf(fout, "%d", &kmaxheap[i]);//利用格式化输入将文件中前k个数据读取到数组中
    }
    //3.建大堆
    for (int i = (k - 1 - 1) / 2; i >= 0; i--)
    {
        AdjustDown(kmaxheap, k, i);//使用向下调整算法
    }
    //4.读取N-k个数据然后一一对比
    int val = 0;
    while (!feof(fout))
    {
        int fscanfreturn = fscanf(fout, "%d", &val);
        if (val < kmaxheap[0])
        {
            kmaxheap[0] = val;
            AdjustDown(kmaxheap, k, 0);
        }
    }
    fclose(fout);
    //5.打印前最小的k个数据
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", kmaxheap[i]);
    }
    printf("\n");
    free(kmaxheap);
}
int main()
{
    _make();
    HeapSort_Topk(10);
    return 0;
}