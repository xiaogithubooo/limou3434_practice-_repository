#include <iostream>
#include <unistd.h>
#include <signal.h>

unsigned int Seconds = 100;
int n = 0;

void alarmHandler(int signum)
{
    n = alarm(0);
    std::cout << n << std::endl;
    alarm(n);
}

int main()
{
    signal(SIGALRM, alarmHandler);
    alarm(Seconds);
    std::cout << "Alarm set for " << Seconds << " seconds" << std::endl;
    
    while (true)
    {
        sleep(1);
    }

    return 0;
}
