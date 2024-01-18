#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    close(1);
    int fd = open("limou.txt", O_WRONLY|O_TRUNC|O_CREAT);//会覆盖文件的内容
    if(fd < 0)
    {
        perror("open");
        return 1;
    }
    fprintf(stdout, "you can see me, success\n");
}
