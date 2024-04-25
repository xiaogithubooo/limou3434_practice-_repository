//thread.hpp(多进程死循环服务端)

/* 使用方法
void Func(int data) { sleep(3); std::cout << data << std::endl; }
Thread<int>::thread_func_t func = Func;
Thread<int> t("threadName", func, 10);
std::cout << t.ThreadName() << std::endl;
t.Start();
while(t.IsRunning() == false) { t.Join(); }
*/

#pragma once
#include <iostream>
#include <string>
#include <functional>
#include <pthread.h>

//线程类
template<class T>
class Thread
{
public:
    //线程方法类型
    using thread_func_t = std::function<void(T)>;

private:
    //线程调用方法
    static void* ThreadRoutine(void* args) //使用 static 去除方法的 this 参数, 这是一种小技巧
    {
        Thread* ts = static_cast<Thread*>(args);
        ts->_func(ts->_data);
        ts->_isrunning = false; //标识运行结束
        return nullptr;
    }


public:
    //创建线程对象: 传递线程名、thread_func_t 类型方法(void(T))、T 类型参数
    Thread(const std::string& threadname, thread_func_t func, T data)
        : _tid(0)
        , _threadname(threadname)
        , _isrunning(false)
        , _func(func)
        , _data(data)
    {}

    //运行线程对象
    bool Start()
    {
        if (pthread_create(&_tid, nullptr, ThreadRoutine, this) == 0) //如果创建线程成功
        {
            //注意这里传递的线程方法对应的参数时 this 指针, 原因是 ThreadRoutine 是一个 static 函数
            _isrunning = true;
            return true;
        }
        else //创建失败
        {
            return false; //构造默认就是 false
        }
    }

    //释放线程对象
    bool Join()
    {
        if (_isrunning == false) 
            return true;

        if (pthread_join(_tid, nullptr) == 0)
        {
            _isrunning = false;
            return true;
        }

        return false;
    }

    //取得线程名字
    std::string ThreadName()
    {
        return _threadname;
    }

    //取得线程状态
    bool IsRunning()
    {
        return _isrunning;
    }


private:
    pthread_t _tid;             //线程 id
    std::string _threadname;    //线程名字
    bool _isrunning;            //线程状态
    thread_func_t _func;        //线程方法
    T _data;                    //线程数据
};