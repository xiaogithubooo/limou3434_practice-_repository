#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//1.链表结构体
typedef struct listNode
{
    int val;//节点存储的值
    struct listNode* next;//指向下一个节点
    struct listNode* prev;//指向上一个节点
    int size;//链表的长度
}listNode;
//2.初始化循环链表
listNode* InitList(listNode* plist)
{
    //1.购买节点并且初始化
    listNode* cache = (listNode*)malloc(sizeof(listNode));
    if (!cache) exit(-1);
    cache->val = 0;
    cache->next = NULL;
    cache->prev = NULL;
    cache->size = 0;
    //2.构建一个自循环的循环头节点
    plist = cache;
    plist->next = plist;
    plist->prev = plist;
    return plist;
}
//3.尾插函数
void PushBack(listNode* plist, int x)
{
    listNode* cache = (listNode*)malloc(sizeof(listNode));
    if (!cache) exit(-1);
    cache->val = x;
    cache->next = NULL;
    cache->prev = NULL;

    listNode* prev = plist->prev;
    plist->prev = cache;
    prev->next = cache;
    cache->next = plist;
    cache->prev = prev;

    plist->size++;
}
//4.删除pos指向的节点
void DelPos(listNode* pos)
{
    listNode* prev = pos->prev;
    listNode* next = pos->next;
    prev->next = next;
    next->prev = prev;
    free(pos);
    pos = NULL;
}
int main()
{
    //1.输入猴子的数量
    int N = 0;
    scanf("%d", &N);

    //2.初始化循环链表
    listNode* plist = NULL;
    plist = InitList(plist);

    //3.循环构成循环链表
    for (int i = 1; i <= N; i++)
    {
        PushBack(plist, i);//不断尾插
    }

    //4.查找计数并且删除
    int j = 1;
    listNode* cur = plist->next;
    
    while (plist->size > 1)
    {
        listNode* next = cur->next;
        if (j == 3)
        {
            DelPos(cur);
            plist->size--;
            j = 0;
        }
        j++;
        cur = next;
        if (cur == plist)
        {
            cur = next->next;
        }
    }
    printf("%d", cur->val);
    return 0;
}

//方法一：根据最小公倍数的定义
int smallestEvenMultiple(int n)
{
    for (int i = 1; i <= 2 * n; i++)
    {
        if (i % n == 0 && i % 2 == 0)
            return i;
    }
    return 0;
}
//方法二：根据数学公式
int smallestEvenMultiple(int n)
{
    //2和任何正偶数的最大公约数是2
    //2和任何正奇数的最大公约数是1
    //根据“最大公约数*最小公倍数==两个数相乘”得出如下语句
    return n % 2 == 0 ? (2 * n) / 2 : (2 * n) / 1;
}