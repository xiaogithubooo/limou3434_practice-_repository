#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
#include "Queue.h"
//# 0.ջ�Ͷ��еĸ�ϰĿ��
//>		0.1.��ϰջ�Ͷ��еľ������
//x			0.1.1.���븴ϰ
//x			0.1.2.��˺һ��ջ
//x			0.1.3.��˺һ������
//>		0.2.ջ�Ͷ��е������ϰ��Ŀ
//			0.2.1.��Ч�����ţ�https://leetcode.cn/problems/valid-parentheses/
//			0.2.2.�ö���ʵ��ջ��https://leetcode.cn/problems/implement-stack-using-queues/
//			0.2.3.��ջʵ�ֶ��У�https://leetcode.cn/problems/implement-queue-using-stacks/
//			0.2.4.���ѭ�����У�https://leetcode.cn/problems/design-circular-queue/
//>		0.3.����������ϰ��Ŀ
//			0.3.1.�����г���վʱ�䣺https://leetcode.cn/problems/calculate-delayed-arrival-time/
//			0.3.2.��Сż������https://leetcode.cn/problems/smallest-even-multiple/
//			0.3.3.ͳ��һ��Բ�е����Ŀ��https://leetcode.cn/problems/queries-on-number-of-points-inside-a-circle/
//x			0.3.4.����֮�ͣ�https://leetcode.cn/problems/add-two-integers/solutions/1413083/liang-zheng-shu-xiang-jia-by-leetcode-so-6cq1/
//			0.3.5.������ͣ�https://leetcode.cn/problems/sum-multiples/description/
//			0.3.6.�жϸ�����Ƿ�����ӽ��֮�ͣ�https://leetcode.cn/problems/root-equals-sum-of-children/
//			0.3.7.���Goal��������https://leetcode.cn/problems/goal-parser-interpretation/
//			0.3.8.���鴮����https://leetcode.cn/problems/concatenation-of-array/

//# 1.ջ��ջ�Ĳ�������
//> 1.1.ջ�Ĳ���
void test_1()
{
    Stack st1;//����һ��ջ�ṹ��
    StackInit(&st1);//��ʼ�����ջ
    StackPush(&st1, 1);//ѹջ
    StackPush(&st1, 2);//ѹջ
    StackPush(&st1, 3);//ѹջ
    StackPush(&st1, 4);//ѹջ
    StackPush(&st1, 5);//ѹջ

    printf("<ջ��>\n");
    while (!StackEmpty(&st1))//ֻҪջ��Ϊ�վͽ���ѭ��
    {
        printf("%3d\n", StackTop(&st1));//ȡ��ջ��Ԫ�ز��Ҵ�ӡ
        StackPop(&st1);//ɾ��ջ��Ԫ��
    }
    printf("<ջ��>\n");
    //StackPop(&st1);//�Ƿ�ɾ��
    //StackPop(&st1);//�Ƿ�ȡջ��Ԫ��
    StackDestroy(&st1);//����ջ�ṹ��
}
//> 1.2.���еĲ���
void test_2()
{
    Queue q;
    QueueInit(&q);//��ʼ������
    QueuePush(&q, 5);//���β
    QueuePush(&q, 4);//���β
    QueuePush(&q, 3);//���β
    QueuePush(&q, 2);//���β
    QueuePush(&q, 1);//���β
    printf("��ͷ->");
    while (!QueueEmpty(&q))//��Ϊ�ǿն��������ѭ��
    {
        printf("%d->", QueueFront(&q));//ȡ����ͷ�����Ҵ�ӡ
        QueuePop(&q);
    }
    printf("��β");
    //QueueFront(&q);//�Ƿ�ȡ����ͷ
    //QueuePop(&q);//�Ƿ�ɾ����ͷ
    QueueDestroy(&q);
}

int main()
{
	//test_1();//ջ��������
    //test_2();//���в�������
	return 0;
}

