//thread_pool.hpp(�̳߳ذ汾�ķ����)

/* ʹ�÷���
�������� ����t;
ThreadPool<��������>* tp = ThreadPool<��������>* GetInstance(�߳�����);
tp->Start(); //�����̳߳�, �ڲ��ᴴ������̵߳ȴ���������
tp->Push(����t); //��������
tp->Wait(); //�ֶ��ͷ��̳߳��ڵĶ��߳�
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


//�̳߳������̵߳����ݷ�װ��
class PoolThreadData
{
public:
    PoolThreadData(std::string name) : _threadName(name) {}


public:
    std::string _threadName;
};


//�̳߳���
template<class T = Task>
class ThreadPool
{
private:
    static const int gNumOfThread; //Ĭ�ϵ��߳������Ĵ�С


private:
    //���������ȴ�(�򵥷�װ����, ���Կ���дһ��������������)
    void ThreadWait()
    {
        pthread_cond_wait(&_cond, &_mutex);
    }

    //������������(�򵥷�װ����, ���Կ���дһ��������������)
    void ThreadWaitUp()
    {
        pthread_cond_signal(&_cond);
    }

    //TODO: ����Ƿ���Ҫ�����̳߳�����
    void CheckSelf()
    {
        //������������������������ˮλ��, �����߳�����С���߳����ˮλ��
        //_num_of_task > _task_high_water && _numOfThread < _thread_high_water;
        //�Ǿʹ�����������߳̽��и���, ���Ҹ����߳�����

        //������������ٹ����������ˮλ��, �����߳��������ڻ�����߳����ˮλ��
        //_num_of_task == _task_low_water && _numOfThread >= _thread_high_water;
        //�Ǿ����ٵ����ֵ��߳̽��м���, ���Ҹ����߳�����

        ; //TODO����һ��չҲ������, �Ժ��л���ʵϰ
    }

    //�̻߳ص�����
    void ThreadRun(PoolThreadData& td)
    {
        //TODO: �ڵ���֮ǰ��ȫ���Լ��һ���̵߳ĸ���, ������������, ����������ʱ����, �����Ժ��л����ٽ�����չ
        //CheckSelf();

        while (true)
        {
            T t;

            //ȡ������(����)
            {
                LockGuard lockguard(&_mutex);
                while (_taskQueue.empty()) //���ϼ��, ��ֹα����, ���統һ�����߳� A ���Ȼ������, �������߳����ڻ�ȡͬһ��������������, �������߳� A ��������������н��е�һ�������, �������̲߳�Ӧ�ü�������, ����Ӧ�õȴ���������(�ȴ�������Դ����)
                {
                    ThreadWait(); //�������Ϊ��������ȴ�(�߳�ͬ��), ��������������Դ��, ���߳������ﱻ������, ���ǻ��ٴν���һ����������
                    //(1)������Ҳ�Ͱ���, ������������;
                    //(2)�����û�������ͻ���������������, ���ȵ�������ʱ, �Ծ���Ҫ���м��, �������п��ܳ�������ٻ��ѵ����
                }

                //ȡ������
                t = _taskQueue.front();
                _taskQueue.pop();
            }

            //ִ���������⣩
            t();

            _log.LogMessage(DEBUG, "%s->ThreadRun() succeed in %s %d", td._threadName.c_str(), __FILE__, __LINE__);
        }
    }

    //���캯��, ��������߳�
    ThreadPool(int numOfThread = gNumOfThread) 
        : _numOfThread(numOfThread)
    {
        //��ʼ��������������
        pthread_mutex_init(&_mutex, nullptr);
        pthread_cond_init(&_cond, nullptr);

        //��������߳�
        for (int i = 0; i < _numOfThread; i++)
        {
            //�߳���
            std::string tName = "thread_";
            tName += std::to_string(i);

            //���ò�����
            PoolThreadData td(tName);

            //���δ�������߳̽����߳��б���
            //Thread<��������> t(�߳���, �̷߳���, ����) �����̷߳�������Ϊ void(T)
            //�����̷߳��� ThreadRun() �����ڷ����Դ� this ָ��, �����ֲ���ʹ�� static, ��˾�ʹ���� STL �� <functional> �� bind() ����, �ú���������ʱ�Զ����ݰ󶨵� this ָ��
            
            //(1)��Ч�Ĳ��뷽��
            //Thread<PoolThreadData> t(tName, std::bind(&ThreadPool<T>::ThreadRun, this, std::placeholders::_1), td); //bind() ���԰ѷ����Ͳ�����, ���õ�ʱ��ֻ��Ҫ����ռλ�����Ĳ�������, ���صĶ�Ӧ����Ҳ�����ռλ���Ķ�
            //_threads.push_back(t);

            //(2)��Ч�Ĳ��뷽��
            Thread<PoolThreadData>::thread_func_t func = std::bind(&ThreadPool<T>::ThreadRun, this, std::placeholders::_1); //���ر����� Thread<PoolThreadData>::thread_func_t = void ThreadRun(PoolThreadData& td) ���͵ĺ���
            _threads.emplace_back(tName, func, td); //emplace_back() �����˲�����(parameter pack)�ķ�ʽ, ����ֱ��������ĩβ������Ԫ��, ��������ǰ������ʱ������߿�������, ��˸��Ӹ�Ч
            
            _log.LogMessage(DEBUG, "Thread()->emplace_back()->%s succeed in %s %d", tName.c_str(), __FILE__, __LINE__);
        }
    }

    //���ÿ�������͸�ֵ����
    ThreadPool(const ThreadPool<T>& tp) = delete;
    const ThreadPool<T>& operator=(const ThreadPool<T>& tp) = delete;

public:
    //��ȡ����ָ�����
    static ThreadPool<T>* GetInstance(int numOfThread = gNumOfThread)
    {
        if (_instance == nullptr) //����֮�����ٴμ��һ��, ��Ϊ�˷�ֹ�����һ���߳����뵽����Դ��, ��ʱ��������Ϊ��ʱ, �������߳�������������������Դ���Դ���������������(����ֻʹ��һ�ε�����������Ч��)
        {
            LockGuard lockGuard(&sig_lock); //����, ��ֹ����߳�ͬʱ����ʱ, �������ɹ����߳������굥�������, ������Ϊ���᲻������Դ���̴߳�����״̬�ָ���, ���������ߵ����(���������)
            if (_instance == nullptr)
            {
                _instance = new ThreadPool(numOfThread); //������뱣֤�̰߳�ȫ, ��Ȼ�ڶ���߳���Ҫͬʱ�����̳߳ص�ʱ��, ���п��ܷ�����ε���������, ���������� if ���
                _log.LogMessage(DEBUG, "GetInstance() succeed in %s %d", __FILE__, __LINE__);
            }
        }

        return _instance; //���ص���ָ��
    }

    //��������߳�
    bool Start()
    {
        for (auto& thread : _threads)
        {
            thread.Start(); //����ÿһ���߳�
            _log.LogMessage(DEBUG, "Start()->%s succeed in %s %d", thread.ThreadName().c_str(), __FILE__, __LINE__);
        }
    }

    //�����������������
    void Push(const T& in)
    {
        //��������������в�������
        LockGuard lockguard(&_mutex);
        _taskQueue.push(in);

        //���λ��������߳�ǰ��ִ��
        ThreadWaitUp();

        _log.LogMessage(DEBUG, "Push() succeed in %s %d", __FILE__, __LINE__);
    }

    //�̳߳ػ���
    void Wait()
    {
        for (auto& thread : _threads)
        {
            thread.Join();
        }
    }

    //�ͷ�������������
    ~ThreadPool()
    {
        pthread_mutex_destroy(&_mutex);
        pthread_cond_destroy(&_cond);
    }

private:
    std::queue<T> _taskQueue; //�������
    std::vector<Thread<PoolThreadData>> _threads; //�߳��б�

    int _numOfThread; //�߳�����
    int _num_of_task; //��������

    pthread_mutex_t _mutex; //������
    pthread_cond_t _cond; //��������

    int _thread_low_water; //���ٵ��߳���, ��ȡ�����ļ�����[��չ]
    int _thread_high_water; //�����߳���, ��ȡ�����ļ�����[��չ]

    int _task_low_water; //���ٵ�������, ��ȡ�����ļ�����[��չ]
    int _task_high_water; //����������, ��ȡ�����ļ�����[��չ]

    static ThreadPool<T>* _instance; //����ָ��
    static pthread_mutex_t sig_lock; //��������Ļ�����, ���������뵥������

    static Log _log; //���ڴ�ӡ��־����־����Ĭ������Ļ�����־, ���� debug �������Ϣ��
};

template<class T>
ThreadPool<T>* ThreadPool<T>::_instance = nullptr; //����ģʽ�ĵ���

template<class T>
pthread_mutex_t ThreadPool<T>::sig_lock = PTHREAD_MUTEX_INITIALIZER;

template<class T>
Log ThreadPool<T>::_log = Log();

template<class T>
const int ThreadPool<T>::gNumOfThread = 10;

//TODO����������һ����չ˼·, ������һ�������̹������ӽ���, ÿ���ӽ����ڲ��Ϳ��Թ�����Ե��̳߳�, �⽫�Ǹ��Ӵ��̳߳ؼ�Ⱥ