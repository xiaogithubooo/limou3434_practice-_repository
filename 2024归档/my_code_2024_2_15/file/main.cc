#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

const char* path = "./bite";
#define mode 0666

int main()
{
    pid_t fd = open(path, O_RDWR | O_CREAT, mode);

    const char wbuffer[1024] = "i like linux!";
    write(fd, wbuffer, sizeof(wbuffer));

    lseek(fd, 0, SEEK_SET); // 将文件指针移动到文件开头

    char rbuffer[1024] = { 0 };
    read(fd, rbuffer, sizeof(rbuffer));

    std::cout << rbuffer << std::endl;

    close(fd);

    return 0;
}