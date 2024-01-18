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
			//ȡ�ö�ͷԪ�أ�Ȼ�󵯳�
			long long cache = QueueFront(&qu);
			QueuePop(&qu);

			//ȡ���¶�ͷԪ�أ��� cache ��Ӻ����
			QueuePush(&qu, (cache + QueueFront(&qu)));

			//����Ƿ�������1���ǾͲ���1
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
	printf("�����������");
	while (scanf("%d", &n) != EOF && n != -1)
	{
		Pascal(n);
		printf("\n");
		printf("�����������");
	}
	return 0;
}