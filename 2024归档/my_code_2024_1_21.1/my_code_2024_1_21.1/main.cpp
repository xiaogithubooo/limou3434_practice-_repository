//����ģʽ��������ģʽ
#include <iostream>
using namespace std;

//����ģʽ����һ���õ�ʱ���ٴ������ֳ�������
template <class Type>
class SlackerModel
{
public:
	static SlackerModel* GetInstance() //5.��ȡʵ�����󣬲��������û��޷�ֱ�Ӵ��������������Ҳ���뾲̬��Ա�����������û�����
	{
		if (_inst == nullptr)
		{
			_inst = new SlackerModel<Type>; //6.��ָ��Ϊ�գ��򴴽�һ�����󣨲��ұ�ֻ֤���ڵ�һ�ε��õ�ʱ�򴴽���������ʱ����ԭ�ⲻ�����أ�
			//��������ģʽ�ĵ��������� new �����ģ����ö������������һ�������̣�����һ�㲻��Ҫ�����Լ��ͷţ����������Ҫ�����Լ��ͷţ������ǽ������̣����̽����ͻ��Զ��ͷţ����ǲ���ϵͳ�ͽ��̵����飬�������迼�ǣ�
		}

		return _inst; //8.���ص�������ָ��
	}

	//7.���ÿ�������͸�ֵ����
	SlackerModel(const SlackerModel<Type>& self) = delete; 
	SlackerModel& operator =(const SlackerModel<Type>& self) = delete; 

	//10.�����ټ��϶Ե��������һЩ��������
	void Add() { _data++; }
	void Print() { cout << "����:" << _data << endl; }

	static void DelInstance() //9.������Ƕ�һ�㣬���Ǿ�֧���û��ֶ��ͷŵ�������
	{
		if (_inst != nullptr)
		{
			delete _inst;
			_inst = nullptr;
		}
	}

private:
	SlackerModel() : _data(Type()) {} //2.�����캯��˽�л�����ֹ�û�ֱ�������⹹�����

	~SlackerModel()
	{
		//12.����������ͬʱ��������Ҫ��һЩ�־û����������磺Ҫ�������д���ļ�����������Ȼ�����������ͷ��ڴ�ռ䣬���ǲ����Զ�����д�����ݣ�������������û��ڴ����е����ݣ�����������Ϊ _data��
		//��ֻ���û������������������������Զ���ĳ־û���������֮���ݾͻᶪʧ
		//fopen(...) ֮������
		cout << "д��������..." << endl; //����ֻ���ô�ӡ����ģ��һ��д�����ݵĹ���
		cout << "����д��ɹ�!" << endl;

		//11.����������ʹ�� new ������Դ������ʹ������ָ�룬��������û��Լ����� delete �Ż��������������
		//�������־û�����������������ñ����û��Լ����� delete��������ǿ��Թ���һ���ڲ��࣬
		//���ڲ��ഴ�������ľ�̬�����Զ��������������������Ķ���ᱻ�Զ��ͷţ�
	}

	class GC //14..�ڲ������ⲿ�����Ԫ��
	{
	public:
		~GC()
		{
			DelInstance(); //13.����û�û���Լ����� DelInstance()���������ͬ�����������Զ�����
		}
	};

private:
	Type _data; //1.�����ڲ������ݣ�������ȫ�ֶ�����һ��
	static SlackerModel<Type>* _inst; //3.���þ�̬��Աָ�������ʹ���� main() ������ǰ�͹���õ�������ָ�루ָ��Ĵ����Ͽ죬��ʱ��ָ��ָ��Ķ���û�б�ʵ�ʴ���������
	static GC _gc; //16.�ڲ�����������ٻ��Զ����������������������г־û�����
};

template <class Type>
SlackerModel<Type>* SlackerModel<Type>::_inst = nullptr; //4.���ⶨ�徲̬��Ա���� _inst

template <class Type>
typename SlackerModel<Type>::GC SlackerModel<Type>::_gc; //17.���ⶨ�徲̬��Ա���� _gc

template class SlackerModel<double>; //18.������ģ���ԭ�򣬵��� _gc ����û�б�ʵ�������������ֻ����ģ������ǰʵ������һ���࣬�����޷����� _gc ����������

int main()
{
	SlackerModel<double>::GetInstance()->Add();
	SlackerModel<double>::GetInstance()->Add();
	SlackerModel<double>::GetInstance()->Add();
	SlackerModel<double>::GetInstance()->Print();

	//delete SlackerModel<double>::GetInstance(); //��Ȼ������ô��ƣ��������ǲ��Ƽ�������ϣ���� main() �������Զ�����
	
	SlackerModel<double>::GetInstance()->DelInstance(); //19.�û������Լ���ǰ���ã�������������
	
	//���������滹��ĳЩ����...
	
	return 0;
}
//20.Ҳ���Բ�ʹ������� main() ���ý����Զ����� _gc ����������

//21.��Ȼ���������Ҫ���־û���������ô�й� GC �Ĵ���Ϳ���ȥ��...
 
//22.����ģʽҲ��ʾ���ǣ�
//(1) �����Щ������Ҫ�� main() ǰ��������ʹ�� static �ĳ�Ա����
//(2) �����Щ������Ҫ�� main() ���������Գ���ʹ����������ָ����ڲ�������