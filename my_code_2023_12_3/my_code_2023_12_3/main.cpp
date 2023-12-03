#include <iostream>
using namespace std;

double Division(int a, int b)
{
	if (b == 0)
	{
		throw "Division by zero condition";
	}
	return (double)a / (double)b;
}

void Function()
{
	int* array = new int[10];//(5)new ����Ҳ���׳��쳣

	try 
	{
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << '\n';//(1)�����׳��������쳣��
	}
	catch (...)//(2)�������쳣����������������
	{
		cout << "delete[] " << array << '\n';//(3)���ͷ� array����ֹ�ڴ�й¶
		delete[] array;
		throw;//(4)���½��쳣�׳�ȥ
	}
	cout << "delete[] " << array << '\n';
	delete[] array;
}

int main()
{
	try
	{
		Function();
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
	catch (const exception& e)//(6)new ���쳣���������ﱻ����
	{
		cout << e.what() << '\n';
	}
	return 0;
}

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