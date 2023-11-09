#define _CRT_SECURE_NO_WARNINGS 1
#include "link.h"

int main()
{
	//1.用户输入数据
	int len = 0;			//多项式的长度
	int ret = 0;			//消除某些警告

	//1.1.输入表达式1
	printf("请输入 多项式1 的 [大小]:\n");
	ret = scanf("%d", &len);
	if(len != 0)
		printf("请输入 多项式1 的每一项的 [系数,幂数]，\n"
		"系数和幂数用英文逗号隔开，每一项用空格隔开，"
		"并且需要从最高次到最低次输入:\n");
	ListNode* pl1 = ListInit();
	while (len--)
	{
		//存储到结点
		Data data = { 0,0 };
		ret = scanf("%d,%d", &data._coefficient, &data._power);
		ListPushBack(pl1, data);
	}

	//1.2.输入表达式2
	printf("请输入 多项式2 的 [大小]:\n");
	ret = scanf("%d", &len);
	if (len != 0)
		printf("请输入 多项式2 的每一项的 [系数,幂数]，\n"
		"系数和幂数用英文逗号隔开，每一项用空格隔开，"
		"并且需要从最高次到最低次输入:\n");
	ListNode* pl2 = ListInit();
	while (len--)
	{
		//存储到结点
		Data data = { 0,0 };
		ret = scanf("%d,%d", &data._coefficient, &data._power);
		ListPushBack(pl2, data);
	}

	//2.相加并且输出相加结果
	printf("表达式1:");
	ListPrint(pl1);
	printf("表达式2:");
	ListPrint(pl2);
	printf("相加为 :");
	ListPrint(AddTwoLink(pl1, pl2));

	//3.销毁相关资源
	ListDestory(pl1);
	ListDestory(pl2);
	return 0;
}