#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
#include "Queue.h"
//# 0.栈和队列的复习目标
//>		0.1.复习栈和队列的具体代码
//x			0.1.1.代码复习
//x			0.1.2.手撕一个栈
//x			0.1.3.手撕一个队列
//>		0.2.栈和队列的相关练习题目
//			0.2.1.有效的括号：https://leetcode.cn/problems/valid-parentheses/
//			0.2.2.用队列实现栈：https://leetcode.cn/problems/implement-stack-using-queues/
//			0.2.3.用栈实现队列：https://leetcode.cn/problems/implement-queue-using-stacks/
//			0.2.4.设计循环队列：https://leetcode.cn/problems/design-circular-queue/
//>		0.3.其他力扣练习题目
//			0.3.1.计算列车到站时间：https://leetcode.cn/problems/calculate-delayed-arrival-time/
//			0.3.2.最小偶倍数：https://leetcode.cn/problems/smallest-even-multiple/
//			0.3.3.统计一个圆中点的数目：https://leetcode.cn/problems/queries-on-number-of-points-inside-a-circle/
//x			0.3.4.两数之和：https://leetcode.cn/problems/add-two-integers/solutions/1413083/liang-zheng-shu-xiang-jia-by-leetcode-so-6cq1/
//			0.3.5.倍数求和：https://leetcode.cn/problems/sum-multiples/description/
//			0.3.6.判断根结点是否等于子结点之和：https://leetcode.cn/problems/root-equals-sum-of-children/
//			0.3.7.设计Goal解析器：https://leetcode.cn/problems/goal-parser-interpretation/
//			0.3.8.数组串联：https://leetcode.cn/problems/concatenation-of-array/

//# 1.栈和栈的测试用例
//> 1.1.栈的测试
void test_1()
{
    Stack st1;//创建一个栈结构体
    StackInit(&st1);//初始化这个栈
    StackPush(&st1, 1);//压栈
    StackPush(&st1, 2);//压栈
    StackPush(&st1, 3);//压栈
    StackPush(&st1, 4);//压栈
    StackPush(&st1, 5);//压栈

    printf("<栈顶>\n");
    while (!StackEmpty(&st1))//只要栈不为空就进入循环
    {
        printf("%3d\n", StackTop(&st1));//取出栈顶元素并且打印
        StackPop(&st1);//删除栈顶元素
    }
    printf("<栈底>\n");
    //StackPop(&st1);//非法删除
    //StackPop(&st1);//非法取栈顶元素
    StackDestroy(&st1);//销毁栈结构体
}
//> 1.2.队列的测试
void test_2()
{
    Queue q;
    QueueInit(&q);//初始化队列
    QueuePush(&q, 5);//入队尾
    QueuePush(&q, 4);//入队尾
    QueuePush(&q, 3);//入队尾
    QueuePush(&q, 2);//入队尾
    QueuePush(&q, 1);//入队尾
    printf("队头->");
    while (!QueueEmpty(&q))//若为非空队列则进入循环
    {
        printf("%d->", QueueFront(&q));//取出队头，并且打印
        QueuePop(&q);
    }
    printf("队尾");
    //QueueFront(&q);//非法取出队头
    //QueuePop(&q);//非法删除队头
    QueueDestroy(&q);
}

int main()
{
	//test_1();//栈测试用例
    //test_2();//队列测试用例
	return 0;
}

