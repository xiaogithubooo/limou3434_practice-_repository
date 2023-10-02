#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define SIZE 101
#define MAX_RATE 100
#define STYLE '#'
#define STIME 1000 * 200//1000 * 1000 = 1秒
const char* str = "-\\|/";
typedef void (*callback_t)(int);
void process_plus(int rate)//参数是传递了比例，根据比例来打一段进度条
{
    static char bar[SIZE];
    int num = strlen(str);//旋转光标字符的长度
    static int i = 0;
    if (rate <= MAX_RATE && rate >= 0)
    {
        printf("[%-100s][%3d%%][%c]\r", bar, rate, str[i % num]);//这里换成i是为了让旋转光标能够运作，不受进度条控制，可以让用户职别这个进度条究竟是卡住了还是仍在加载
        fflush(stdout);
        bar[rate] = STYLE;
        i++;
    }
    if (rate == MAX_RATE)//主要是用在下一次别的程序调用这个函数的时候，避免进度条数组中还有#
    {
        memset(bar, '\0', sizeof(bar));
    }//这样程序可以适用与不同的任务
}
void download_1(callback_t cb)//第一个下载任务，正常调用
{
    int rate = 0;
    while (rate <= 100)
    {
        (*cb)(rate++);//回调函数
        usleep(STIME);//单位为毫秒
    }
    printf("\n");
}
void download_2(callback_t cb)//第二个加载任务，模拟还在加载的情况，不是进度条程序卡住
{
    int rate = 0;
    while (rate <= 100)
    {
        (*cb)(rate++);//回调函数

        if (rate == 50)
        {
            rate = 49;
        }

        usleep(STIME);//单位为毫秒
    }
    printf("\n");
}
int main()
{
    download_1(process_plus);
    download_2(process_plus);
    return 0;
}
