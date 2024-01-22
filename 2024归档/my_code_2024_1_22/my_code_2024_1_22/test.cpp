//#include <iostream>
//#include <map>
//using namespace std;
//
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
//	map<string, string> _dict;
//	int _n = 0;
//
//	static B* _inst;
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
//	static gc _gc;
//};
//
//B* B::_inst = nullptr;
//B::gc B::_gc;
//
//int main()
//{
//	B::GetInstance()->Add("1", "limou");
//	B::GetInstance()->Add("2", "dimou");
//	B::GetInstance()->Add("3", "eimou");
//	B::GetInstance()->Add("4", "iimou");
//	B::GetInstance()->Print();
//
//	return 0;
//}