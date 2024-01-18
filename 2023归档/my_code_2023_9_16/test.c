#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define SIZE 101
#define MAX_RATE 100
#define STYLE '#'
#define STIME 1000 * 40//1000 * 1000 = 1秒
const char* str = "\\|/-";
void process();
int main()
{
    process();
    return 0;
}
void process()
{
    int rate = 0;
    char bar[SIZE] = {0};
    int num = strlen(str);

    while(rate <= MAX_RATE)
    {
        printf("[%-100s][%d%%][%c]\r", bar, rate, str[rate%num]);
        fflush(stdout);
        usleep(STIME);//单位为毫秒
        bar[rate++] = STYLE;
    }
    printf("\n");
}
