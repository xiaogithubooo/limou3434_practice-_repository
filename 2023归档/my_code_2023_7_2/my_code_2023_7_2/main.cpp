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
	//���Ǵ�ʱ������9һ������û�а취�ְ�����Ĵ����ʼ���ڲ��ĳ�Ա
	//���ʱ��Ϳ���ʹ�ö�λnew
	new(pdata1)Data(1);//���Ѿ������ԭʼ�ڴ�ռ��е��ù��캯����ʼ��һ������
	new(pdata2)Data(10);//���Ѿ������ԭʼ�ڴ�ռ��е��ù��캯����ʼ��һ������
	return 0;
}