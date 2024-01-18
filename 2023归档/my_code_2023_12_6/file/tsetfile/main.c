//mian.c
#include <stdio.h>
#include <unistd.h>

int main()
{
    unsigned int i = 0;
    for (i = 0; i >= 0; i = i * i * i)
    {
        printf("%d", i);
        sleep(1);
    }
    return 0;
}