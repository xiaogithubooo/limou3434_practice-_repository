#define _CRT_SECURE_NO_WARNINGS 1

//1、单链表的结构体
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SListDataType;//类型重命名
typedef struct SListNode //单向链表
{
    SListDataType data;//存储数据
    struct SListNode* next;//这里不是结构体套结构体，而单纯是一个指针，指向下一个结构体（就就单纯是一个地址，不会造成无限嵌套的情况）
}SListNode;

//2、申请节点接口函数
void SList_Push_Back(SListNode** pphead, SListDataType x)//(传递一个节点的地址的地址,传递一个数据)
{
    //注意不要写成形参了（即写成SListNode*了，这会导致后面newnode给了形参而没给实参），back是尾部的意思

    //1、首先形成一个单独节点的存储空间，并且给与成员值进行初始化
    SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
    assert(newnode);
    newnode->data = x;//存储一个数据
    newnode->next = NULL;//本次数据为尾节点，因此不可能得知下一个节点的地址

    //2、下面是将上面单独的节点设置为链表的新尾节点
    if (*pphead == NULL)//说明此时链表一个节点都没有
    {
        *pphead = newnode;//那就先创建一个结点
    }
    else//说明此时链表至少有一个节点
    {
        //①找到当前链表尾节点的空指针，直到找到为止
        SListNode* tail = *pphead;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        //②将这个旧尾节点空指针，设置为指向新尾节点的指针
        tail->next = newnode;
    }
}

//3、链表头插接口函数
void SList_Push_Front(SListNode** pphead, SListDataType x)
{
    //1、首先形成一个单独节点的存储空间，并且给与成员值进行初始化
    SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
    assert(newnode);
    newnode->data = x;//存储一个数据
    newnode->next = NULL;
    //2、进行头插
    newnode->next = *pphead;
    *pphead = newnode;
}

//4、链表尾删接口函数
void SList_Pop_Back(SListNode** pphead)
{
    if (*pphead == NULL)//①零个节点
    {
        return;
    }
    else if ((*pphead)->next == NULL)//②一个节点，注意操作符的问题
    {
        free(*pphead);
        *pphead = NULL;
    }
    else//③至少两个节点
    {
        SListNode* prev = NULL;
        SListNode* tail = *pphead;
        while (tail->next != NULL)
        {
            prev = tail;
            tail = tail->next;
        }
        free(tail);
        prev->next = NULL;
    }
}

//5、链表头删接口函数
void SList_Pop_Front(SListNode** pphead)
{
    assert(*pphead);//注意这里是我自己加的，我怕遇到空指针解引用
    SListNode* next = (*pphead)->next;//可以先记下这个头节点存储的指向下一个结点的指针数据
    free(*pphead);//不能直接只用这个语句，会直接找不到后面的链表，间接导致无法回收动态内存，长期的话导致内存泄漏
    *pphead = next;//将原本的第二节点变成头节点
}

//7、链表查找接口函数
SListNode* SList_Find(SListNode* phead, SListDataType x)
{
    SListNode* cur = phead;
    while (cur)//等价于while(cur != NULL)
    {
        if (cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

//8、链表任意插入接口函数（不同教科书不太一样，这里是在pos前面插入x）
//先利用函数void SList_Find查早再进行任意插入
void SList_Insert(SListNode** pphead, SListNode* pos, SListDataType x)
{
    if(pos == *pphead)//0、如果是插在头节点，就相当于头插
    {
        SList_Push_Front(pphead, x);
    }
    else
    {
        //1、先得到一块空间存储新节点
        SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
        assert(newnode);
        newnode->data = x;//存储一个数据
        newnode->next = NULL;//不可能得知下一个节点的地址

        //2、找到指定地址pos的前一个地址，将新节点插入
        SListNode* prev = *pphead;
        while (prev->next != pos)//从第一个链表开始查早，直到有一个节点内部成员存的下一个地址为NULL，这时停留在pos节点的前一个节点
        {
            prev = prev->next;
        }
        prev->next = newnode;
        newnode->next = pos;
    }
}

//9、链表任意删除接口函数（不同教科书不太一样）
//先利用函数void SList_Find查早再进行任意删除
void SList_Erase(SListNode** pphead, SListNode* pos)
{
    assert(*pphead);    
    if (pos == *pphead)//1、如果是插在头节点，就相当于头删
    {
        SList_Pop_Front(pphead);
    }
    else//2、非头节点处
    {
        SListNode* prev = *pphead;
        while (prev->next != pos)//从第一个链表开始查早，直到有一个节点内部成员存的下一个地址为NULL，这时停留在pos节点的前一个节点
        {
            prev = prev->next;
        }
        prev->next = pos->next;//链接两个断开的节点
        free(pos);//释放删除节点的内存
    }
}

//10、链表打印接口函数
void SList_Print(SListNode* phead)
{
    SListNode* cur = phead;//将节点的地址存储起来
    while (cur != NULL)//首次进来节点地址不为空，说明有数据存在节点里面了
    {
        printf("%d -> ", cur->data);
        cur = cur->next;//将cur从“指向首结点的地址”，变成“指向下一个地址值”
    }
    printf("NULL\n");
}
void Test_SList()
{
    SListNode* plist = NULL;//plist指向一个结点，但是由于赋值NULL，所以只是初始化了一个可以指向结点的指针

    //1.测试是否尾插入新节点
    SList_Push_Back(&plist, 1);
    SList_Push_Back(&plist, 2);
    SList_Push_Back(&plist, 3);
    SList_Push_Back(&plist, 4);
    SList_Print(plist);

    //2.测试是否头插入新节点
    SList_Push_Front(&plist, -3);
    SList_Push_Front(&plist, -2);
    SList_Push_Front(&plist, -1);
    SList_Push_Front(&plist, -0);
    SList_Print(plist);

    //3.测试是否尾删除
    SList_Pop_Back(&plist);
    SList_Pop_Back(&plist);
    SList_Print(plist);

    //4.测试是否头删除
    SList_Pop_Front(&plist);
    SList_Pop_Front(&plist);
    SList_Print(plist);

    //5.测试能否搜索某个节点数据
    printf("%p\n", SList_Find(plist, 1));//搜索1的位置

    //6.1.测试能否搜索某个节点，然后在前面插入新节点
    SListNode* pos = SList_Find(plist, 1);
    if (pos)
    {
        SList_Insert(&plist, pos, 30);
    }
    SList_Print(plist);
    //6.2.测试能否在头节点前面插入新节点
    pos = SList_Find(plist, -2);
    if (pos)
    {
        SList_Insert(&plist, pos, 100);
    }
    SList_Print(plist);

    //7.1.测试能否搜索某个节点，然后删除
    pos = SList_Find(plist, -3);
    {
        SList_Erase(&plist, pos);
    }
    SList_Print(plist);
    //7.2.测试能否删除头节点
    pos = SList_Find(plist, 100);
    {
        SList_Erase(&plist, pos);
    }
    SList_Print(plist);
}
int main()
{
    Test_SList();
    return 0;
}