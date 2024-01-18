#include "queue.h"
#include <stdbool.h>
void Pascal(long long n)
{
	if (n <= 0)
	{
		return;
	}

	printf("1\n");

	if (n > 1)
	{
		Queue qu;

		QueueInit(&qu);
		QueuePush(&qu, 1);
		QueuePush(&qu, 1);
		QueuePrint(&qu);

		bool flag = true;

		while (n != QueueSize(&qu))
		{
			//取得队头元素，然后弹出
			long long cache = QueueFront(&qu);
			QueuePop(&qu);

			//取得新队头元素，和 cache 相加后入队
			QueuePush(&qu, (cache + QueueFront(&qu)));

			//检查是否遇到了1，是就插入1
			if (QueueFront(&qu) == 1)
			{
				QueuePush(&qu, 1);
				QueuePrint(&qu);
			}
		}
		QueueDestroy(&qu);
	}
}
int main()
{
	int n = 0;
	printf("请输入阶数：");
	while (scanf("%d", &n) != EOF && n != -1)
	{
		Pascal(n);
		printf("\n");
		printf("请输入阶数：");
	}
	return 0;
}