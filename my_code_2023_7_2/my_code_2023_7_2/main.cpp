#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Data
{
public:
	Data(int a = 0)
		:_a(a)
	{
		cout << "Data(int a = 0)" << this << endl;
	}
	~Data()
	{
		cout << "~Data()" << this << endl;
	}
private:
	int _a;
	int _b;
	int _c;
};
int main()
 {
	Data* pdata1 = new Data;
	Data* pdata2 = (Data*)malloc(sizeof(Data));
	if (!pdata2) exit(-1);
	//但是此时出现了9一个问题没有办法字啊后面的代码初始化内部的成员
	//这个时候就可以使用定位new
	new(pdata1)Data(1);//对已经分配的原始内存空间中调用构造函数初始化一个对象
	new(pdata2)Data(10);//对已经分配的原始内存空间中调用构造函数初始化一个对象
	return 0;
}