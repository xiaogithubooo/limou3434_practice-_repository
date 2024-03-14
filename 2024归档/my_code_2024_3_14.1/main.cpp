//尝试使用线程同步的接口（另一个角度来理解）
#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>
using namespace std;
volatile bool quit = false;
typedef void (*func_t)(const string& name, pthread_mutex_t*pmutex, pthread_cond_t* pcond);
int tickets = 100;

//相关函数集
void func(const string& name, pthread_mutex_t* pmutex, pthread_cond_t* pcond)
{
    while(!quit)
    {
        pthread_mutex_lock(pmutex); //加锁

        //在加锁和解锁之间，往往会进行判断，并且有可能导致效率低下，但是我们可以通过条件变量，把这一判断职责从子线程转移到父进程（降低频繁的判断）
        if (tickets > 0) //假设还有票，不考虑同步问题，让线程们争夺锁即可
        {
            cout << name << " func() running...[" << --tickets << "]" << '\n'; //一旦接受到主线程唤醒信号，就以一定顺序来执行具体的任务，这里只是用打印来模拟而已
            usleep(1000); //抢票对应的响应时间
        }
        else //假设票抢完了，就让子线程直接陷入等待，而不是继续抢夺资源
        {
            cout << "没票了" << name << endl; //如果票真的被抢完了，如果不进行等待，这里背后就会发生大量无意义的加解锁，导致锁资源的浪费，甚至有可能主线程想要放入新的票都无法申请到锁资源
            pthread_cond_wait(pcond, pmutex); //该线程执行到这里时，把锁暂时解开，并且立即被挂起，等待主线程使用 pthread_cond_signal() 唤醒（并且是根据先后顺序来唤醒的），再把锁加上
        }

        pthread_mutex_unlock(pmutex); //解锁
    }
}

//线程数据包
#define T_NUM 4 //线程数量
class ThreadData
{
public:ThreadData(const string& name, func_t func, pthread_mutex_t*pmutex, pthread_cond_t* pcond)
        : _name(name), _func(func), _pmutex(pmutex), _pcond(pcond)
    {}
    string _name;
    func_t _func;
    pthread_mutex_t* _pmutex;
    pthread_cond_t* _pcond;
};

//中间软件层
void* Entry(void* args)
{
    ThreadData* td = (ThreadData*)args; //解包参数，td 在每个线程自己私有栈中保存
    td->_func(td->_name, td->_pmutex, td->_pcond); //函数调用完就会返回这里
    delete td; //继续释放堆资源
    return nullptr;
}

//管理多线程
int main()
{
    //初始互斥锁
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, nullptr);

    //初始条件变量
    pthread_cond_t cond;
    pthread_cond_init(&cond, nullptr);

    //创建多线程
    pthread_t tids[T_NUM];
    for (int i = 0; i < T_NUM; i++)
    {
        string name = "Thread";
        name += to_string(i + 1);
        ThreadData* td = new ThreadData(name, func, &mutex, &cond); //打包参数，让每个线程拿到同样的互斥锁和条件变量，以及对应的线程名字和调用方法
        pthread_create(tids + i, nullptr, Entry, (void*)td);
    }

    //观察多线程现象
    sleep(10); //此时所有子线程都在疯狂抢票，抢完都陷入了等待中...

    //主线程使用线程同步的思路来控制新线程
    pthread_mutex_lock(&mutex); //加锁
    tickets = 1000; //主线程重新加票
    pthread_mutex_unlock(&mutex); //解锁

    int count = 10;
    while(count)
    {
        cout << "resume thread run code ..." << count-- << '\n';
        pthread_cond_signal(&cond); //依次唤醒单个线程
    }

    sleep(10); //此时所有子线程都在疯狂抢票，如果抢完就陷入了等待中，没抢完则抢到一半就会停止

    cout << "ctrl done!" << '\n';
    quit = true;
    pthread_cond_broadcast(&cond); //唤醒所有线程

    //等待释放线程
    for(int i = 0; i < T_NUM; i++)
    {
        pthread_join(tids[i], nullptr);
        cout << "thread: " << tids[i] << "quit" << '\n';
    }
    
    //销毁锁、条件变量
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}