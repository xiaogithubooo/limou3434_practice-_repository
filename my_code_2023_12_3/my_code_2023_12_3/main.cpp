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
	SmartPtr sp(p);//交给智能指针管理
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
//	int* array_1 = new int[10];//(6)new 本身也会抛出异常
//	int* array_2 = new int[10];//(7)new 本身也会抛出异常
//
//	try 
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << '\n';//(1)假设抛出“除零异常”
//	}
//	catch (...)//(2)“除零异常”被代码拦截下来
//	{
//		//(3)先释放 array，防止内存泄露
//		cout << "delete_1[] " << array_1 << '\n';
//		delete[] array_1;
//		cout << "delete_2[] " << array_2 << '\n';
//		delete[] array_2;
//
//		throw;//(4)重新将异常抛出去
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
//	catch (const char* error)//(5)“除零错误”会在这里被接收
//	{
//		cout << error << endl;
//	}
//	catch (const exception& e)//(8)new 的异常可以在这里被接收
//	{
//		cout << e.what() << '\n';
//	}
//	return 0;
//}

////服务器开发中通常使用的异常继承体系
//class Exception
//{
//public:
//	Exception(const string& errmsg, int id)
//		:_errmsg(errmsg),
//		_id(id)
//	{}
//	
//	//查询错误
//	virtual string what() const
//	{
//		return _errmsg;
//	}
//protected:
//	string _errmsg;	//错误信息
//	int _id;		//错误ID
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
//		throw SqlException("权限不足", 100, "select * from name = '张三'");
//	}
//	//throw "xxxxxx";
//}
//
//void CacheMgr()
//{
//	srand(time(0));
//	if (rand() % 5 == 0)
//	{
//		throw CacheException("权限不足", 100);
//	}
//	else if (rand() % 6 == 0)
//	{
//		throw CacheException("数据不存在", 101);
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
//		throw HttpServerException("请求资源不存在", 100, "get");
//	}
//	else if (rand() % 4 == 0)
//	{
//		throw HttpServerException("权限不足", 101, "post");
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
//		catch (const Exception& e) //这里捕获父类对象就可以
//		{
//			//多态
//			cout << e.what() << endl;
//		}
//		catch (...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//	return 0;
//}