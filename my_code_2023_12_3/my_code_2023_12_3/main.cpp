#include <iostream>
using namespace std;

class SmartPtr
{
public:
	SmartPtr(int* ptr)
		: _ptr(ptr)
	{}
	~SmartPtr()
	{
		delete _ptr;
		cout << "delete[] " << _ptr << '\n';
	}
private:
	int* _ptr;
};

int main()
{
	int* p = new int[10];
	SmartPtr sp(p);//��������ָ�����
	return 0;
}

//double Division(int a, int b)
//{
//	if (b == 0)
//	{
//		throw "Division by zero condition";
//	}
//	return (double)a / (double)b;
//}
//
//void Function()
//{
//	int* array_1 = new int[10];//(6)new ����Ҳ���׳��쳣
//	int* array_2 = new int[10];//(7)new ����Ҳ���׳��쳣
//
//	try 
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << '\n';//(1)�����׳��������쳣��
//	}
//	catch (...)//(2)�������쳣����������������
//	{
//		//(3)���ͷ� array����ֹ�ڴ�й¶
//		cout << "delete_1[] " << array_1 << '\n';
//		delete[] array_1;
//		cout << "delete_2[] " << array_2 << '\n';
//		delete[] array_2;
//
//		throw;//(4)���½��쳣�׳�ȥ
//	}
//	cout << "delete_1[] " << array_1 << '\n';
//	delete[] array_1;
//	cout << "delete_2[] " << array_2 << '\n';
//	delete[] array_2;
//}
//
//int main()
//{
//	try
//	{
//		Function();
//	}
//	catch (const char* error)//(5)��������󡱻������ﱻ����
//	{
//		cout << error << endl;
//	}
//	catch (const exception& e)//(8)new ���쳣���������ﱻ����
//	{
//		cout << e.what() << '\n';
//	}
//	return 0;
//}

////������������ͨ��ʹ�õ��쳣�̳���ϵ
//class Exception
//{
//public:
//	Exception(const string& errmsg, int id)
//		:_errmsg(errmsg),
//		_id(id)
//	{}
//	
//	//��ѯ����
//	virtual string what() const
//	{
//		return _errmsg;
//	}
//protected:
//	string _errmsg;	//������Ϣ
//	int _id;		//����ID
//};
//
//class SqlException : public Exception
//{
//public:
//	SqlException(const string& errmsg, int id, const string& sql)
//		: Exception(errmsg, id)
//		, _sql(sql)
//	{}
//
//	virtual string what() const
//	{
//		string str = "SqlException:";
//		str += _errmsg;
//		str += "->";
//		str += _sql;
//		return str;
//	}
//
//private:
//	const string _sql;
//};
//class CacheException : public Exception
//{
//public:
//	CacheException(const string& errmsg, int id)
//		: Exception(errmsg, id)
//	{}
//
//	virtual string what() const
//	{
//		string str = "CacheException:";
//		str += _errmsg;
//		return str;
//	}
//};
//
//class HttpServerException : public Exception
//{
//public:
//	HttpServerException(const string& errmsg, int id, const string& type)
//		: Exception(errmsg, id)
//		, _type(type)
//	{}
//
//	virtual string what() const
//	{
//		string str = "HttpServerException:";
//		str += _type;
//		str += ":";
//		str += _errmsg;
//		return str;
//	}
//
//private:
//	const string _type;
//};
//
//void SQLMgr()
//{
//	srand(time(0));
//	if (rand() % 7 == 0)
//	{
//		throw SqlException("Ȩ�޲���", 100, "select * from name = '����'");
//	}
//	//throw "xxxxxx";
//}
//
//void CacheMgr()
//{
//	srand(time(0));
//	if (rand() % 5 == 0)
//	{
//		throw CacheException("Ȩ�޲���", 100);
//	}
//	else if (rand() % 6 == 0)
//	{
//		throw CacheException("���ݲ�����", 101);
//	}
//	SQLMgr();
//}
//
//void HttpServer()
//{
//	// ...
//	srand(time(0));
//	if (rand() % 3 == 0)
//	{
//		throw HttpServerException("������Դ������", 100, "get");
//	}
//	else if (rand() % 4 == 0)
//	{
//		throw HttpServerException("Ȩ�޲���", 101, "post");
//	}
//	CacheMgr();
//}
//
//int main()
//{
//	while (1)
//	{
//		this_thread::sleep_for(chrono::seconds(1));
//		try {
//			HttpServer();
//		}
//		catch (const Exception& e) //���ﲶ�������Ϳ���
//		{
//			//��̬
//			cout << e.what() << endl;
//		}
//		catch (...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//	return 0;
//}