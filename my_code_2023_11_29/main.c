#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    close(0);
    int fd = open("limou.txt", O_RDONLY);//会覆盖文件的内容
    if(fd < 0)
    {
        perror("open");
        return 1;
    }
    char buffer[1024];
    fread(buffer, 1, sizeof(buffer), stdin);
    printf("%s", buffer);
    fflush(stdout);

    sleep(5);
    close(fd);
    return 0;
}