//#include <iostream>
//#include <map>
//using namespace std;
//
//// 懒汉模式:第一次用的时候再创建（现吃现做）
//// todo:线程安全问题
//// new的懒汉对象一般不需要释放，进程正常结束会释放资源
//// 如果需要做一些动作，比如持久化，那么可以利用gc类static对象搞定
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
//		// 持久化：要求把数据写到文件
//		cout << "数据写到文件" << endl;
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