//#include <iostream>
//#include <map>
//using namespace std;
//
//// ����ģʽ:��һ���õ�ʱ���ٴ������ֳ�������
//// todo:�̰߳�ȫ����
//// new����������һ�㲻��Ҫ�ͷţ����������������ͷ���Դ
//// �����Ҫ��һЩ����������־û�����ô��������gc��static����㶨
//template <class Type = map<string, string>>
//class B
//{
//public:
//	static B* GetInstance()
//	{
//		if (_inst == nullptr)
//		{
//			_inst = new B;
//		}
//
//		return _inst;
//	}
//
//	void Add(const string& key, const string& value)
//	{
//		_dict[key] = value;
//	}
//
//	void Print()
//	{
//		for (auto& kv : _dict)
//		{
//			cout << kv.first << ":" << kv.second << endl;
//		}
//		cout << endl;
//	}
//
//	static void DelInstance()
//	{
//		if (_inst)
//		{
//			delete _inst;
//			_inst = nullptr;
//		}
//	}
//
//	class gc
//	{
//	public:
//		~gc()
//		{
//			DelInstance();
//		}
//	};
//
//private:
//	B()
//	{}
//
//	~B()
//	{
//		// �־û���Ҫ�������д���ļ�
//		cout << "����д���ļ�" << endl;
//	}
//
//	B(const B& aa) = delete;
//	B& operator=(const B& aa) = delete;
//
//private:
//	Type _dict;
//	int _n = 0;
//	static B* _inst;
//	static gc _gc;
//};
//
//template <class Type>
//B<Type>* B<Type>::_inst = nullptr;
//
//template <class Type>
//typename B<Type>::gc B<Type>::_gc;
//
//template class B<map<string, string>>;
//int main()
//{
//	B<>::GetInstance()->Add("1", "limou");
//	B<>::GetInstance()->Add("2", "dimou");
//	B<>::GetInstance()->Add("3", "eimou");
//	B<>::GetInstance()->Add("4", "iimou");
//	B<>::GetInstance()->Print();
//	return 0;
//}