#define _CRT_SECURE_NO_WARNINGS 1
#define LIST_NUM 50
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//1.静态链表结构体
/*需要注意的是：
* 1.1.静态链表的每一个有效元素的cur存储下一个有效元素的索引，但是“第一个空闲数组元素的cur存储第一个空闲数组元素的下标”，“最后一个有效数组元素的cur存储0，表示没有指向数据”
* 1.2.静态链表的最后一个空闲数组元素的cur存储的是整个链表的“第一个有效数据”的索引（也就是说，当链表为空的时候，最后的一个元素的cur存储0）
*/
typedef int ElemType;
typedef struct StaticLinkList
{
	ElemType data;//存储数据
	int cur;//存储下一个数组的索引
}StaticLinkList;
//2.计算链表长度
int LitsLenght(StaticLinkList* plist)
{
	;
}
//3.初始化函数
void InitList(StaticLinkList* plist, ElemType listNum)
{
	//1.检查指针的有效性
	assert(plist);
	//2.开始初始化
	int i = 0;
	for (i = 0; i < listNum - 1; i++)
	{
		plist[i].cur = i + 1;
	}
	plist[i].cur = 0;
}
//4.插入函数
//4.1.先找到空闲数组元素的下标，功能类似与malloc函数
int MallocSLL(StaticLinkList* plist)
{
	//1.取出空闲数组元素的下标
	int i = plist[0].cur;
	//2.修改第一个空闲元素数组的cur，指向新的空闲数组下标
	plist[0].cur = plist[i].cur;
	return i;
}
//4.2.根据找到的元素来实现任意插入
void InsertList(StaticLinkList* plist, int index, ElemType x)
{
	//1.检查指针有效性和index的合法性
	assert(plist);
	if (index < 1 || index > LitsLenght(plist))	exit(-1);
	//2.开始插入元素
	int i = MallocSLL(plist);//先找到空闲数组元素的下标
	plist[i].data = x;
}

int main()
{
	StaticLinkList list[LIST_NUM];
	InitList(list, LIST_NUM);//初始化
	return 0;
}