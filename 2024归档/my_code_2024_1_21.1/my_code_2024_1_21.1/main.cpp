//����ģʽ��������ģʽ
#include <iostream>
using namespace std;

//����ģʽ����һ���õ�ʱ���ٴ������ֳ�������
template <class Type>
class SlackerModel
{

};



////����ģʽ���Ѷ�����ǰ�����ã�������� ����/main ����ʱ����������ʱ��Ҫ����Ҫʹ��ȫ�ֱ�����ʵ�֣�һ���޷�ֱ�Ӵ��������������ض��壬Ӧ��ʹ�þ�̬������
//template <class Type>
//class HungryManModel
//{
//public:
//	static HungryManModel* GetInstance() //4.��ȡʵ�����󣬲��������û��޷�ֱ�Ӵ��������������Ҳ���뾲̬��Ա�����������û�����
//	{
//		return &_inst; //5.���ص�������
//	}
//
//	HungryManModel(const HungryManModel<Type>& self) = delete; //12.���ÿ�������
//
//	HungryManModel& operator =(const HungryManModel<Type>& self) = delete; //14.���ø�ֵ���أ�һ����ÿ�������Ҳ����ø�ֵ���أ�
//
//	//6.�����ټ��϶Ե��������һЩ��������
//	void Add()
//	{
//		_data++;
//	}
//
//	void Print()
//	{
//		cout << "����:" << _data << endl;
//	}
//
//private:
//	HungryManModel() //2.�����캯��˽�л�����ֹ�û�ֱ�������⹹�����
//		: _data(Type())
//	{}
//
//private:
//	Type _data; //1.�����ڲ������ݣ�������ȫ�ֶ�����һ��
//	static HungryManModel<Type> _inst; //3.���þ�̬��Ա������ʹ���� main() ������ǰ�͹���õ�������ע�������̬��Ա���ڲ���û���Լ������Լ�����Ϊ��̬�����洢�ھ�̬���������ڶ����ڲ�
//};
//
//template <class Type>
//HungryManModel<Type> HungryManModel<Type>::_inst; //��Ȼ�����ⶨ�壬���Ǹþ�̬������������ģ���̬��Ա������˿��Ե��ù��캯��
//
//int main()
//{
//	//HungryManModel<int> a; //7.�޷�ֱ��������ֱ�Ӵ�������
//	//HungryManModel<int>* pa = new HungryManModel<int>(); //8.�޷�ֱ��������ֱ�Ӵ�������
//	HungryManModel<int>* p = HungryManModel<int>::GetInstance(); //9.��ȡ��������
//
//	//10.���õ�������ķ���
//	p->Add();
//	p->Print(); //��� 1
//	HungryManModel<int>::GetInstance()->Add();
//	HungryManModel<int>::GetInstance()->Print(); //��� 2
//
//	//11.���ֻ���һ��ȱ�ݣ�û�н��ÿ������죬������������������ģ��������ľͱ�¶����������
//	//HungryManModel<int> copy(*HungryManModel<int>::GetInstance()); //����
//
//	//HungryManModel<int>::GetInstance()->Add();
//	//HungryManModel<int>::GetInstance()->Print(); //��� 3
//
//	//copy.Print(); //������� 2
//
//	//13.��������һЩ����ֵֹĲ������Լ����Լ���ֵ...��ȻҲ������ʲô���������Է���һ������Ҳ�Ѹ�ֵ���ظ�����
//	//*HungryManModel<int>::GetInstance() = *HungryManModel<int>::GetInstance();
//
//	//15.��������ͬ���͵ĵ������󣬵���ÿһ�����͵Ķ����ڴ����ж�ֻ�����һ��
//	HungryManModel<double>::GetInstance()->Add();
//	HungryManModel<double>::GetInstance()->Print();
//
//	HungryManModel<long>::GetInstance()->Add();
//	HungryManModel<long>::GetInstance()->Print();
//	return 0;
//}
