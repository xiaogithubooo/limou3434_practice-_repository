//thread.hpp(�������ѭ�������)

/* ʹ�÷���
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

//�߳���
template<class T>
class Thread
{
public:
    //�̷߳�������
    using thread_func_t = std::function<void(T)>;

private:
    //�̵߳��÷���
    static void* ThreadRoutine(void* args) //ʹ�� static ȥ�������� this ����, ����һ��С����
    {
        Thread* ts = static_cast<Thread*>(args);
        ts->_func(ts->_data);
        ts->_isrunning = false; //��ʶ���н���
        return nullptr;
    }


public:
    //�����̶߳���: �����߳�����thread_func_t ���ͷ���(void(T))��T ���Ͳ���
    Thread(const std::string& threadname, thread_func_t func, T data)
        : _tid(0)
        , _threadname(threadname)
        , _isrunning(false)
        , _func(func)
        , _data(data)
    {}

    //�����̶߳���
    bool Start()
    {
        if (pthread_create(&_tid, nullptr, ThreadRoutine, this) == 0) //��������̳߳ɹ�
        {
            //ע�����ﴫ�ݵ��̷߳�����Ӧ�Ĳ���ʱ this ָ��, ԭ���� ThreadRoutine ��һ�� static ����
            _isrunning = true;
            return true;
        }
        else //����ʧ��
        {
            return false; //����Ĭ�Ͼ��� false
        }
    }

    //�ͷ��̶߳���
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

    //ȡ���߳�����
    std::string ThreadName()
    {
        return _threadname;
    }

    //ȡ���߳�״̬
    bool IsRunning()
    {
        return _isrunning;
    }


private:
    pthread_t _tid;             //�߳� id
    std::string _threadname;    //�߳�����
    bool _isrunning;            //�߳�״̬
    thread_func_t _func;        //�̷߳���
    T _data;                    //�߳�����
};