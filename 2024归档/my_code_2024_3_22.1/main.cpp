//尝试使用线程同步的接口
#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>
using namespace std;

volatile bool quit = false;

//函数方法
typedef void (*func_t)(const string& name, pthread_mutex_t*pmutex, pthread_cond_t* pcond);
class ThreadData
{
public:
   ThreadData(const string& name, func_t func, pthread_mutex_t*pmutex, pthread_cond_t* pcond)
       : _name(name), _func(func), _pmutex(pmutex), _pcond(pcond)
   {}
   string _name;
   func_t _func;
   pthread_mutex_t* _pmutex;
   pthread_cond_t* _pcond;
};

void func1(const string& name, pthread_mutex_t*pmutex, pthread_cond_t* pcond)
{
   while (!quit)
   {
       pthread_mutex_lock(pmutex);
       pthread_cond_wait(pcond, pmutex); //等待，默认执行到这里时，当前线程会被立即挂起
       cout << name << " running..." << '\n';
       pthread_mutex_unlock(pmutex);
   }
}
void func2(const string& name, pthread_mutex_t*pmutex, pthread_cond_t* pcond)
{
   while (!quit)
   {
       pthread_mutex_lock(pmutex);
       pthread_cond_wait(pcond, pmutex); //等待，默认执行到这里时，当前线程会被立即挂起
       cout << name << " running..." << '\n';
       pthread_mutex_unlock(pmutex);
   }
}
void func3(const string& name, pthread_mutex_t*pmutex, pthread_cond_t* pcond)
{
   while (!quit)
   {
       pthread_mutex_lock(pmutex);
       pthread_cond_wait(pcond, pmutex); //等待，默认执行到这里时，当前线程会被立即挂起
       cout << name << " running..." << '\n';
       pthread_mutex_unlock(pmutex);
   }
}
void func4(const string& name, pthread_mutex_t*pmutex, pthread_cond_t* pcond)
{
   while (!quit)
   {
       pthread_mutex_lock(pmutex);
       pthread_cond_wait(pcond, pmutex); //等待，默认执行到这里时，当前线程会被立即挂起
       cout << name << " running..." << '\n';
       pthread_mutex_unlock(pmutex);
   }
}

//中间软件层
void* Entry(void* args)
{
   ThreadData* td = (ThreadData*)args; //解包参数，td 在每个线程自己私有栈中保存
   td->_func(td->_name, td->_pmutex, td->_pcond); //函数调用完就会返回这里
   delete td; //继续释放堆资源
   return nullptr;
}

#define T_NUM 4 //线程数量

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
   func_t funcs[T_NUM]= { func1, func2, func3, func4 };
   for (int i = 0; i < T_NUM; i++)
   {
       string name = "Thread";
       name += to_string(i + 1);
       ThreadData* td = new ThreadData(name, funcs[i], &mutex, &cond); //打包参数，让每个线程拿到同样的锁和条件变量
       pthread_create(tids + i, nullptr, Entry, (void*)td);
   }

   //由于主线程没有开始控制，因此导致所有新线程和主线程都处于阻塞状态
   sleep(5);

   //主线程使用线程同步的思路赖控制新线程
   int count = 10;
   while (count)
   {
       cout << "resume thread run code ..." << count-- << '\n';
       pthread_cond_signal(&cond); //依次唤醒单个线程
   }

   cout << "ctrl done!" << '\n';
   quit = true;
   pthread_cond_broadcast(&cond); //唤醒所有线程

   //等待释放线程
   for (int i = 0; i < T_NUM; i++)
   {
       pthread_join(tids[i], nullptr);
       cout << "thread: " << tids[i] << "quit" << '\n';
   }

   //销毁锁、条件变量
   pthread_mutex_destroy(&mutex);
   pthread_cond_destroy(&cond);

   return 0;
}
