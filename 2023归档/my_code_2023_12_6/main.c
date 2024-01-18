#include "file.h"
#include <stdio.h>

int main()
{
    MyFILE* fp = Myfopen("./limou.txt", "w");
    if(!fp)
    {
        perror("Myfopen()");
        return 1;
    }

    int cnt = 20;
    const char* msg = "Hello, I am limou3434.\n";
    while(cnt--)
    {
        Mywrite(msg, strlen(msg), fp);
        sleep(1);
    }

    Myfclose(fp);

    return 0;
}