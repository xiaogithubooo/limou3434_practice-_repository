#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

const char* path = "./limou.txt";
#define mode 0666

int main()
{
    pid_t fd = open(path, O_RDWR | O_CREAT, mode);

    const char wbuffer[1024] = "i like linux!";
    write(fd, wbuffer, sizeof(wbuffer));

    while (true);
    //在循环期间去其他 bash 下检查程序没结束之前，
    //limou.txt 文件内是否有内容存在，结果为有，
    //则证明 write() 操作是会刷新磁盘的，一旦刷新，
    //该操作就会立马让所有使用 limou.txt 文件的进程感知
    //都会知道 limou.txt 的内容和大小被修改

    close(fd);

    return 0;
}