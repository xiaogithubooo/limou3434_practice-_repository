//thread_pool.hpp(懒汉-单例模式的线程池)

/* 使用方法
ThreadPool<任务类型> tp = ThreadPool<任务类型>();
tp->Start();        //启动线程池，内部会创建多个线程等待处理任务
tp->Push(任务);     //推送任务
tp->Wait();         //手动释放线程池内的多线程
*/

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

static const int gDefaultNum = 10;

class PoolThreadData
{
public:
    PoolThreadData(std::string name)
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
    void ThreadRun(PoolThreadData &td)
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
            t();
            _log.LogMessage(DEBUG, "%s->ThreadRun() succeed in %s %d", td._threadName.c_str(), __FILE__, __LINE__);
        }
    }

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
            PoolThreadData td(tName);
            //依次创建多个线程
            //Thread<PoolThreadData> t(tName, std::bind(&ThreadPool<T>::ThreadRun, this, std::placeholders::_1), td); //bind() 可以把方法和参数绑定，调用的时候只需要传入占位符处的参数即可，对应的包装类类型也需要根据占位符改动
            //_threads.push_back(t);
            _threads.emplace_back(tName,
                std::bind(&ThreadPool<T>::ThreadRun, this, std::placeholders::_1),
                td
            ); //emplace_back() 采用了参数包（parameter pack）的方式，允许直接在容器末尾构造新元素，而无需提前创建临时对象或者拷贝对象，更加高效
            _log.LogMessage(DEBUG, "Thread()->emplace_back()->%s succeed in %s %d", tName.c_str(), __FILE__, __LINE__);
        }
    }

    //禁用拷贝构造和赋值重载
    ThreadPool(const ThreadPool<T>& tp) = delete;
    const ThreadPool<T>& operator=(const ThreadPool<T>& tp) = delete;

public:
    //获取单例指对象
    static ThreadPool<T>* GetInstance(int num_of_thread = gDefaultNum)
    {
        if (_instance == nullptr) //这里之所以再次检查一遍，是为了防止早有一个线程申请到锁资源后，单例对象不为空时，其他线程依旧在无脑申请锁资源尝试创建单例对象的情况（提高效率）
        {
            LockGuard lockGuard(&sig_lock); //加锁，防止多个线程同时运行时，抢夺锁成功的线程申请完单例对象后，其他因为抢夺不到锁资源的线程从阻塞状态恢复后，依旧往下走的情况（避免二义性）
            if (_instance == nullptr)
            {
                _instance = new ThreadPool(num_of_thread); //这里必须保证线程安全，不然在多个线程需要同时申请线程池的时候，会有可能发生多次单例的申请，多次重入这个 if 语句
                _log.LogMessage(DEBUG, "GetInstance() succeed in %s %d", __FILE__, __LINE__);
            }
        }

        return _instance;
    }

    //启动多个线程
    bool Start()
    {
        for (auto& thread : _threads)
        {
            thread.Start();
            _log.LogMessage(DEBUG, "Start()->%s succeed in %s %d", thread.ThreadName().c_str(), __FILE__, __LINE__);
        }
    }

    //插入任务到任务队列中
    void Push(const T& in)
    {
        //加锁向任务队列中插入任务，并且依次唤醒其他线程前来执行
        LockGuard lockguard(&_mutex);
        _q.push(in);
        ThreadWaitUp();
        _log.LogMessage(DEBUG, "Push() succeed in %s %d", __FILE__, __LINE__);
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
    std::vector<Thread<PoolThreadData>> _threads; //线程列表
    
    int _num_of_thread; //线程数量
    int _num_of_task; //任务数量
    
    pthread_mutex_t _mutex; //互斥锁
    pthread_cond_t _cond; //条件变量

    int _thread_low_water; //最少的线程数，读取配置文件即可[拓展]
    int _thread_high_water; //最多的线程数，读取配置文件即可[拓展]
    
    int _task_low_water; //最少的任务数，读取配置文件即可[拓展]
    int _task_high_water; //最多的任务数，读取配置文件即可[拓展]

    static ThreadPool<T>* _instance; //单例指针
    static pthread_mutex_t sig_lock; //单例对象的互斥锁，避免多次申请单例对象

    static Log _log; //用于打印日志的日志对象（默认向屏幕输出日志，捕获 debug 级别的消息）
};

template<class T>
ThreadPool<T>* ThreadPool<T>::_instance = nullptr;

template<class T>
pthread_mutex_t ThreadPool<T>::sig_lock = PTHREAD_MUTEX_INITIALIZER;

template<class T>
Log ThreadPool<T>::_log = Log();

//TODO：这里再做一个拓展思路，假设让一个主进程管理多个子进程，每个子进程内部就可以管理各自的线程池，这将是个庞大线程池集群
