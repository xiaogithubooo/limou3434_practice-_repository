#include<stdio.h>
#include<unistd.h>
int main()
{
    while(1)
    {
        printf("I am a code!%d\n", getpid());
        sleep(1);
    }
    return 0;//错误码和退出码达成一致
}