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
//	//aԭ��������aΪ���������Ԫ�ص�ַ����a[0]�ĵ�ַ
//	//������a��ǿ��ת��Ϊָ��4��Ԫ�������ָ��
//	printf("a_ptr=%p, p_ptr=%p\n", &a[4][2], &p[4][2]);
//	printf("%p, %d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	return 0;
//}

//int main()
//{
//	int a[3][4] = { 0 };
//	printf("%zd\n", sizeof(a));//ʲô���壿
//	printf("%zd\n", sizeof(a[0][0]));//ʲô���壿
//	printf("%zd\n", sizeof(a[0]));//ʲô���壿
//	printf("%zd\n", sizeof(a[0] + 1)); // ʲô���壿
//	printf("%zd\n", sizeof(*(a[0] + 1))); // ʲô���壿
//	printf("%zd\n", sizeof(a + 1));//ʲô���壿
//	printf("%zd\n", sizeof(*(a + 1)));//ʲô���壿
//	printf("%zd\n", sizeof(&a[0] + 1));//ʲô���壿
//	printf("%zd\n", sizeof(*(&a[0] + 1)));//ʲô���壿
//	printf("%zd\n", sizeof(*a));//ʲô���壿
//	printf("%zd\n", sizeof(a[3]));//ʲô���壿
//}

////> 1.1.�ѵ�ʵ�֣������Ǵ�ѽṹ��
//typedef int HPDataType;
//typedef struct Heap
//{
//    HPDataType* _a;
//    int _size;
//    int _capacity;
//}Heap;
////  1.1.1.�ѵĳ�ʼ��
//void HeapInit(Heap* hp)
//{
//    assert(hp);
//    hp->_a = NULL;
//    hp->_size = hp->_capacity = 0;
//}
////  1.1.2.�ѵ�����
//void HeapDestory(Heap* hp)
//{
//    ;
//}
////  1.1.3.�ѵĲ��루�ѵĲ���Ҫ���ִ��/С�ѵ�������
////  �������������ϵ����㷨
//void AdjustDwon(HPDataType* arr, int childi)
//{
//    assert(arr);
//    int parenti = (childi - 1) / 2;
//    while (childi > 0)//���ﲻ����parent
//    {
//        //1.�����㸸�ڵ�����ӽڵ�ͽ���
//        if (arr[parenti] < arr[childi])
//        {
//            int tmp = arr[parenti];
//            arr[parenti] = arr[childi];
//            arr[childi] = tmp;
//
//            childi = parenti;//2.��������
//            parenti = (childi - 1) / 2;
//        }
//        else
//        {
//            break;
//        }
//    }
//    //3.����һ�£����ϵ����㷨��ʱ�临�Ӷ�ΪO(log(2)(n))
//}
//void HeapPush(Heap* hp, HPDataType x)
//{
//    assert(hp);
//    //1.�鿴�����Ƿ���㣬���������
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
//    //2.ֱ�Ӳ���
//    hp->_a[hp->_size] = x;
//    hp->_size++;
//    //3.ʹ�����ϵ����㷨
//    AdjustDwon(hp->_a, hp->_size - 1);
//}
////  1.1.4.�ѵ�ɾ��
//void HeapPop(Heap* hp)
//{
//    ;
//}
////   1.1.5.ȡ�Ѷ�������
//HPDataType HeapTop(Heap* hp)
//{
//    ;
//}
////   1.1.6.�ѵ����ݸ���
//int HeapSize(Heap* hp)
//{
//    ;
//}
////   1.1.7.�ѵ��п�
//int HeapEmpty(Heap* hp)
//{
//    ;
//}
