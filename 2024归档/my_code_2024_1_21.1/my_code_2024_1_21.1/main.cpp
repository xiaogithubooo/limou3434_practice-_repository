//单例模式——懒汉模式
#include <iostream>
using namespace std;

//懒汉模式：第一次用的时候再创建（现吃现做）
template <class Type>
class SlackerModel
{
public:
	static SlackerModel* GetInstance() //5.获取实例对象，并且由于用户无法直接创建对象，这个函数也必须静态成员函数，方便用户调用
	{
		if (_inst == nullptr)
		{
			_inst = new SlackerModel<Type>; //6.若指针为空，则创建一个对象（并且保证只有在第一次调用的时候创建，其他的时候都是原封不动返回）
			//由于懒汉模式的单例对象是 new 出来的，而该对象的生命周期一般跟随进程，所以一般不需要我们自己释放（极少情况需要我们自己释放），而是交给进程，进程结束就会自动释放（这是操作系统和进程的事情，我们无需考虑）
		}

		return _inst; //8.返回单例对象指针
	}

	//7.禁用拷贝构造和赋值重载
	SlackerModel(const SlackerModel<Type>& self) = delete; 
	SlackerModel& operator =(const SlackerModel<Type>& self) = delete; 

	//10.这里再加上对单例对象的一些操作方法
	void Add() { _data++; }
	void Print() { cout << "数据:" << _data << endl; }

	static void DelInstance() //9.如果考虑多一点，我们就支持用户手动释放单例对象
	{
		if (_inst != nullptr)
		{
			delete _inst;
			_inst = nullptr;
		}
	}

private:
	SlackerModel() : _data(Type()) {} //2.将构造函数私有化，禁止用户直接在类外构造对象

	~SlackerModel()
	{
		//12.但是析构的同时，可能需要做一些持久化操作（比如：要求把数据写到文件），进程虽然正常结束会释放内存空间，但是不会自动进行写入数据（这里的数据是用户在代码中的数据，本代码体现为 _data）
		//而只有用户调用了析构函数，才能做自定义的持久化操作，否之数据就会丢失
		//fopen(...) 之类的语句
		cout << "写入数据中..." << endl; //这里只是用打印语句简单模拟一下写入数据的过程
		cout << "数据写入成功!" << endl;

		//11.由于这里是使用 new 申请资源，除非使用智能指针，否则必须用户自己调用 delete 才会调用析构函数，
		//进而做持久化操作，但是我们最好避免用户自己调用 delete，因此我们可以构造一个内部类，
		//让内部类创建出来的静态对象自动调用析构函数（创建的对象会被自动释放）
	}

	class GC //14..内部类是外部类的友元类
	{
	public:
		~GC()
		{
			DelInstance(); //13.如果用户没有自己调用 DelInstance()，则这里会同构析构函数自动调用
		}
	};

private:
	Type _data; //1.对象内部的数据，假设在全局独有这一份
	static SlackerModel<Type>* _inst; //3.设置静态成员指针变量，使得在 main() 被调用前就构造好单例对象指针（指针的创建较快，此时的指针指向的对象还没有被实际创建出来）
	static GC _gc; //16.内部类对象，其销毁会自动引发析构函数，进而进行持久化操作
};

template <class Type>
SlackerModel<Type>* SlackerModel<Type>::_inst = nullptr; //4.类外定义静态成员变量 _inst

template <class Type>
typename SlackerModel<Type>::GC SlackerModel<Type>::_gc; //17.类外定义静态成员变量 _gc

template class SlackerModel<double>; //18.由于类模板的原因，导致 _gc 对象没有被实例化出来，因此只能让模板类提前实例化出一份类，否则无法调用 _gc 的析构函数

int main()
{
	SlackerModel<double>::GetInstance()->Add();
	SlackerModel<double>::GetInstance()->Add();
	SlackerModel<double>::GetInstance()->Add();
	SlackerModel<double>::GetInstance()->Print();

	//delete SlackerModel<double>::GetInstance(); //虽然可以这么设计，但是我们不推荐，我们希望在 main() 结束后自动调用
	
	SlackerModel<double>::GetInstance()->DelInstance(); //19.用户可以自己提前调用，析构单例对象
	
	//假设这下面还有某些代码...
	
	return 0;
}
//20.也可以不使用这句在 main() 调用结束自动调用 _gc 的析构函数

//21.当然，如果不需要做持久化操作，那么有关 GC 的代码就可以去除...
 
//22.懒汉模式也提示我们：
//(1) 如果有些动作想要在 main() 前做，可以使用 static 的成员变量
//(2) 如果有些动作想要在 main() 后做，可以尝试使用类似智能指针或内部类析构