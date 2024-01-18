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
//���µ����㷨
void AdjustDown(HPDataType* arr, int arrsize, int parenti)
{
    int childi = parenti * 2 + 1;
    while (childi < arrsize)
    {
        //1.������������
        if (childi + 1 < arrsize && arr[childi] < arr[childi + 1])
        {
            childi++;
        }
        //2.�ж��Ƿ���Ҫ����
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
//ģ��������ݴ洢���ļ���
void _make(void)
{
    //������
    int n = 10000;//�������ݸ���
    int m = 10000;//�������ݷ�Χ
    int x = 0;//�洢���ݱ���
    srand((unsigned)time(0));//���������
    const char* file = "data.txt";//�����ļ�����
    FILE* fin = fopen(file, "w");//��ֻд�ķ�ʽ�򿪸��ļ���������ļ������ھ��Զ������������򸲸�ԭ�е�����
    if (fin == NULL)//��ʧ�ܾ���ʾ����
    {
        perror("fopen error");
        return;
    }
    for (size_t i = 0; i < n; ++i)//����д��n���������
    {
        x = rand() % m;
        fprintf(fin, "%d\n", x);
    }
    fclose(fin);//�رո��ļ�
}
//ģ����Դ������ݵ�Top-k�Ķ���
void HeapSort_Topk(int k)
{
    //1.���ļ�
    const char* file = "data.txt";
    FILE* fout = fopen(file, "r");
    if (fout == NULL)//��ʧ�ܾ���ʾ
    {
        perror("fopen error");
        return;
    }
    //2.��ֻ��ȡk������
    HPDataType* kmaxheap = (HPDataType*)malloc(sizeof(HPDataType) * k);//���ٶ�Ӧ��ѵĿռ�
    if (kmaxheap == NULL)//����ʧ�ܾ���ʾ
    {
        perror("malloc error");
        return;
    }
    for (int i = 0; i < k; i++)
    {
        int fscanfreturn = fscanf(fout, "%d", &kmaxheap[i]);//���ø�ʽ�����뽫�ļ���ǰk�����ݶ�ȡ��������
    }
    //3.�����
    for (int i = (k - 1 - 1) / 2; i >= 0; i--)
    {
        AdjustDown(kmaxheap, k, i);//ʹ�����µ����㷨
    }
    //4.��ȡN-k������Ȼ��һһ�Ա�
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
    //5.��ӡǰ��С��k������
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