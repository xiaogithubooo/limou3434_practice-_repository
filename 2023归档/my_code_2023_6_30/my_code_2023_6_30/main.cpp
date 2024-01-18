#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class A
{
public:
    A(int a = 0)
        : _a(a)
    {
        cout << "A(int a = 0):" << this << endl;
    }
    ~A()
    {
        cout << "~A():" << this << endl;
    }
private:     
    int _a;
};
int main()
{
    //p1现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因为构造函数没 有执行
    A* p1 = (A*)malloc(sizeof(A));
    new(p1)A;
    p1->~A();
    free(p1);

    A* p2 = (A*)operator new(sizeof(A));
    new(p2)A(10);
    p2->~A();
    operator delete(p2);
    return 0;
}

//class ListNode
//{
//public:
//	ListNode(int val)
//		:_val(val),_next(nullptr)
//	{}
//	void* operator new(size_t n)
//	{
//		cout << "void* operator new(size_t n)->STL内存池allocator申请" << endl;
//		//使用内存池和模板
//		void* obj = alloc.allocate(1);
//		return obj;
//	}
//	void operator delete(void* ptr)
//	{
//		cout << "void operator delete(void* ptr)->内存池deallocate释放" << endl;
//		alloc.deallocate((ListNode*)ptr, 1);
//	}
//private:
//	int _val;
//	ListNode* _next;
//	static allocator<ListNode> alloc;
//};
//allocator<ListNode> ListNode::alloc;
//int main()
//{
//	ListNode* node1 = new ListNode(1);
//	ListNode* node2 = new ListNode(2);
//	ListNode* node3 = new ListNode(3);
//	delete node1;
//	delete node2;
//	delete node3;
//}

//class Data
//{
//public:
//	Data(int data)
//		:_data(data)
//	{
//		cout << "Data()" << endl;
//	}
//	~Data()
//	{
//		cout << "~Data()" << endl;
//	}
//private:
//	int _data;
//};
//void* operator new(size_t size, const char* fileName, const char* funcName, size_t lineNo)
//{
//	void* p = ::operator new(size);
//	cout << "cout" << fileName << "-" << funcName << "-" << lineNo << "-" << p << "-" << size << endl;
//	return p;
//}void operator delete(void* p, const char* fileName, const char* funcName, size_t lineNo)
//{
//	cout << "delete" << fileName << "-" << funcName << "-" << lineNo << "-" << p << endl;
//	::operator delete(p);
//}
//int main()
//{
//	int* p1 = new(__FILE__, __FUNCTION__, __LINE__) int;
//	operator delete(p1, __FILE__, __FUNCTION__, __LINE__);
//
//#ifdef _DEBUG
//	#define new new(__FILE__, __FUNCTION__, __LINE__)
//	#define delete(p) operator delete(p, __FILE__, __FUNCTION__, __LINE__)
//#endif
//
//	int* p2 = new int;
//	delete(p2);
//	return 0;
//}

/*	
	//1.初始化单个自定义类型变量
	Data* dd1 = new Data(10);
	delete dd1;

	//2.初始化自定义类型的数组
	//2.1.错误初始化
	//Data* dd2 = new Data[10]{1,2,3,4};
	//delete[] dd2;
	//2.2.正确初始化
	Data* dd3 = new Data[10]{ {1},{2},{3},{4},{5},{6},{7},{8},{9},{10} };//而且必须要每个元素都初始化，不能有漏
	delete[] dd3;
*/
//void Test()
//{
//	//1.动态申请一个int类型的空间
//	int* ptr1 = new int;
//
//	//2.动态申请一个int类型的空间并初始化为10
//	int* ptr2 = new int(10);
//
//	// 动态申请10个int类型的空间
//	int* ptr3 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	for (int i = 0; i < 10; i++)
//	{
//		cout << ptr3[i] << " ";
//	}
//
//	delete ptr1;
//	delete ptr2;
//	delete[] ptr3;//注意方括号必须带上
//}
//int main()
//{
//	Test();
//	return 0;
//}

//#define SIZE 10
//int main()
//{
//
//	int* arr = (int*)malloc(sizeof(int) * SIZE);
//	if (arr == NULL)
//	{
//		exit(-1);
//	}
//	for (int i = 0; i < SIZE; i++)
//	{
//		arr[i] = i * i;
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	for (int j = 0; j < SIZE; j++)
//	{
//		free(arr + j);
//	}
//	return 0;
//}