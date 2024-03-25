//thread_pool.hpp
#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <functional>
#include <unistd.h>
#include "log.hpp"
#include "thread.hpp"
#include "lock_guard.hpp"
#include "task.hpp"

static Log log = Log(); //用于打印日志的日志对象（默认向屏幕输出日志，捕获 debug 级别的消息）

static const int gDefaultNum = 5;

class ThreadData
{
public:
    ThreadData(std::string name)
        : _threadName(name)
    {}
public:
    std::string _threadName;
};

template<class T>
class ThreadPool
{
private:
    //条件变量等待
    void ThreadWait()
    {
        pthread_cond_wait(&_cond, &_mutex);
    }

    //条件变量唤醒
    void ThreadWaitUp()
    {
        pthread_cond_signal(&_cond);
    }

    //检查是否需要调整线程池设置
    void CheckSelf()
    {
        //如果任务数量超过了任务最高水位线，并且线程数量小于线程最高水位线
        //_num_of_task > _task_high_water && _num_of_thread < _thread_high_water;
        //那就创建出更多的线程进行负载，并且更新线程数量
        
        //如果任务数量少过于任务最低水位线，并且线程数量大于或等于线程最高水位线
        //_num_of_task == _task_low_water && _num_of_thread >= _thread_high_water;
        //那就销毁掉部分的线程进行减负，并且更新线程数量
        
        ; //TODO：这一拓展也是留着，以后有机会实习
    }

    //线程回调方法
    void ThreadRun(ThreadData &td)
    {
        //在调用之前完全可以检查一下线程的负载，进而做出调整，这里我们暂时不做，留着以后有机会再进行拓展
        CheckSelf();

        while(true)
        {
            //取得任务（锁内）
            T t;
            {
                LockGuard lockguard(&_mutex);
                while(_q.empty()) //防止伪唤醒
                {
                    ThreadWait(); //任务队列为空则陷入等待
                }
                t = _q.front();
                _q.pop();
            }
            
            //执行任务（锁外）
            log.LogMessage(DEBUG, "%s->ThreadRun()->%d succeed in %s %d", td._threadName.c_str(), t(), __FILE__, __LINE__);
        }
    }


public:
    //构造函数，创建多个线程
    ThreadPool(int num_of_thread = gDefaultNum)
        : _num_of_thread(num_of_thread)
    {
        //初始化锁和条件变量
        pthread_mutex_init(&_mutex, nullptr);
        pthread_cond_init(&_cond, nullptr);
    
        //创建多个线程
        for (int i = 0; i < _num_of_thread; i++)
        {
            //线程名
            std::string tName = "thread_";
            tName += std::to_string(i);
            //调用参数包
            ThreadData td(tName);
            //依次创建多个线程
            //Thread<ThreadData> t(tName, std::bind(&ThreadPool<T>::ThreadRun, this, std::placeholders::_1), td); //bind() 可以把方法和参数绑定，调用的时候只需要传入占位符处的参数即可，对应的包装类类型也需要根据占位符改动
            //_threads.push_back(t);
            _threads.emplace_back(tName,
                std::bind(&ThreadPool<T>::ThreadRun, this, std::placeholders::_1),
                td
            ); //emplace_back() 采用了参数包（parameter pack）的方式，允许直接在容器末尾构造新元素，而无需提前创建临时对象或者拷贝对象，更加高效
            log.LogMessage(DEBUG, "Thread()->emplace_back()->%s succeed in %s %d", tName.c_str(), __FILE__, __LINE__);
        }
    }

    //启动多个线程
    bool Start()
    {
        for (auto& thread : _threads)
        {
            thread.Start();
            log.LogMessage(DEBUG, "Start()->%s succeed in %s %d", thread.ThreadName().c_str(), __FILE__, __LINE__);
        }
    }

    //插入任务到任务队列中
    void Push(const T& in)
    {
        //加锁向任务队列中插入任务，并且依次唤醒其他线程前来执行
        LockGuard lockguard(&_mutex);
        _q.push(in);
        ThreadWaitUp();
        log.LogMessage(DEBUG, "Push() succeed in %s %d", __FILE__, __LINE__);
    }

    //线程池回收
    void Wait()
    {
        for(auto& thread : _threads)
        {
            thread.Join();
        }
    }

    //释放锁和条件变量
    ~ThreadPool()
    {
        pthread_mutex_destroy(&_mutex);
        pthread_cond_destroy(&_cond);
    }

private:
    std::queue<T> _q; //任务队列
    std::vector<Thread<ThreadData>> _threads; //线程列表
    
    int _num_of_thread; //线程数量
    int _num_of_task; //任务数量
    
    pthread_mutex_t _mutex; //互斥锁
    pthread_cond_t _cond; //条件变量

    int _thread_low_water; //最少的线程数，读取配置文件即可[拓展]
    int _thread_high_water; //最多的线程数，读取配置文件即可[拓展]
    
    int _task_low_water; //最少的任务数，读取配置文件即可[拓展]
    int _task_high_water; //最多的任务数，读取配置文件即可[拓展]
};

//TODO：这里再做一个拓展思路，假设让一个主进程管理多个子进程，每个子进程内部就可以管理各自的线程池，这将是个庞大线程池集群
