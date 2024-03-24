//thread.hpp(线程池)
/* 使用方式
Thread<回调参数类型> t("thread_name", 回调方法, 回调参数包);
t.Start(); //启动线程
t.Join(); //释放线程
t.IsRunning(); //线程运行状态
st.ThreadName(); //线程名
*/
#pragma once

#include <iostream>
#include <string>
#include <functional>
#include <pthread.h>

template<class T>
//using func_t = std::function<void(T)>;
using func_t = std::function<void(T&)>;

template<class T>
class Thread
{
private: 
    //处理事务
    static void *ThreadRoutine(void *args) //去除方法的 this 参数
    {
        Thread *ts = static_cast<Thread *>(args);
        ts->_func(ts->_data);
        return nullptr;
    }
    
    //初始对象
public:
    Thread(const std::string& threadname, func_t<T> func, T& data)
        :_tid(0), _threadname(threadname), _isrunning(false), _func(func), _data(data)
    {}

    //启动线程
    bool Start()
    {
        int n = pthread_create(
            &_tid, //存储线程 id
            nullptr, //获取线程属性（但是置空，我们暂时不需要）
            ThreadRoutine, //线程方法
            this //线程方法参数，就是获得一个 Thread 对象的指针
        );
        if(n == 0) 
        {
            _isrunning = true;
            return true;
        }
        else
        {
            return false;
        }
    }
    
    //释放线程
    bool Join()
    {
        if(!_isrunning)
            return true;
        
        int n = pthread_join(_tid, nullptr);
        if(n == 0)
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
    pthread_t _tid; //线程 id
    std::string _threadname; //线程名字
    bool _isrunning; //线程状态
    func_t<T> _func; //线程方法
    T _data; //线程数据
};
