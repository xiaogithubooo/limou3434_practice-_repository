#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//void function(int* a)
//{
//	printf("a")
//}
//int main()
//{
//
//	return 0;
//}
int function_1(int x)
{
	x = x * x;
	return x;
}
void function_2(int(*parr)[4][3][2][6][7])
{
	printf("hello word\n");
	int(*p)(int) = function_1;
	printf("%d\n", (*p)(3));
	int(*(*pp))(int) = p;
	printf("%d\n", p(5));
	int((*(*(arr[2]))))(int) = { pp, pp };
}
int main()
{
	int arr[3][4][3][2][6][7];
	function_2(arr);
	return 0;
}

//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	//a原本代表以a为名数组的首元素地址，即a[0]的地址
//	//而现在a被强制转化为指向4个元素数组的指针
//	printf("a_ptr=%p, p_ptr=%p\n", &a[4][2], &p[4][2]);
//	printf("%p, %d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	return 0;
//}

//int main()
//{
//	int a[3][4] = { 0 };
//	printf("%zd\n", sizeof(a));//什么含义？
//	printf("%zd\n", sizeof(a[0][0]));//什么含义？
//	printf("%zd\n", sizeof(a[0]));//什么含义？
//	printf("%zd\n", sizeof(a[0] + 1)); // 什么含义？
//	printf("%zd\n", sizeof(*(a[0] + 1))); // 什么含义？
//	printf("%zd\n", sizeof(a + 1));//什么含义？
//	printf("%zd\n", sizeof(*(a + 1)));//什么含义？
//	printf("%zd\n", sizeof(&a[0] + 1));//什么含义？
//	printf("%zd\n", sizeof(*(&a[0] + 1)));//什么含义？
//	printf("%zd\n", sizeof(*a));//什么含义？
//	printf("%zd\n", sizeof(a[3]));//什么含义？
//}

////> 1.1.堆的实现（以下是大堆结构）
//typedef int HPDataType;
//typedef struct Heap
//{
//    HPDataType* _a;
//    int _size;
//    int _capacity;
//}Heap;
////  1.1.1.堆的初始化
//void HeapInit(Heap* hp)
//{
//    assert(hp);
//    hp->_a = NULL;
//    hp->_size = hp->_capacity = 0;
//}
////  1.1.2.堆的销毁
//void HeapDestory(Heap* hp)
//{
//    ;
//}
////  1.1.3.堆的插入（堆的插入要保持大堆/小堆的条件）
////  辅助函数：向上调整算法
//void AdjustDwon(HPDataType* arr, int childi)
//{
//    assert(arr);
//    int parenti = (childi - 1) / 2;
//    while (childi > 0)//这里不能用parent
//    {
//        //1.不满足父节点大于子节点就交换
//        if (arr[parenti] < arr[childi])
//        {
//            int tmp = arr[parenti];
//            arr[parenti] = arr[childi];
//            arr[childi] = tmp;
//
//            childi = parenti;//2.迭代更新
//            parenti = (childi - 1) / 2;
//        }
//        else
//        {
//            break;
//        }
//    }
//    //3.补充一下，向上调整算法的时间复杂度为O(log(2)(n))
//}
//void HeapPush(Heap* hp, HPDataType x)
//{
//    assert(hp);
//    //1.查看容量是否充足，不足就扩容
//    if (hp->_capacity == hp->_size)
//    {
//        int newcapacity = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
//        HPDataType* cache = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * newcapacity);
//        if (!cache)
//        {
//            perror("realloc fail\n");
//            return;
//        }
//        hp->_a = cache;
//        hp->_capacity = newcapacity;
//    }
//    //2.直接插入
//    hp->_a[hp->_size] = x;
//    hp->_size++;
//    //3.使用向上调整算法
//    AdjustDwon(hp->_a, hp->_size - 1);
//}
////  1.1.4.堆的删除
//void HeapPop(Heap* hp)
//{
//    ;
//}
////   1.1.5.取堆顶的数据
//HPDataType HeapTop(Heap* hp)
//{
//    ;
//}
////   1.1.6.堆的数据个数
//int HeapSize(Heap* hp)
//{
//    ;
//}
////   1.1.7.堆的判空
//int HeapEmpty(Heap* hp)
//{
//    ;
//}
