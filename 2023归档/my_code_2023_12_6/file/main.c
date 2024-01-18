#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    //1.关闭标准输入
    close(0);

    //2.打开新的文件，自动赋予文件标识符为 0
    int fd = open("limou.txt", O_RDONLY);//此时文件内是有内容的
    if(fd < 0)
    {
        perror("open");
        return 1;
    }

    //3.自定义一个缓冲区 buffer，用于存储读取到的数据
    char buffer[1024] = { 0 };
    fread(buffer, 1, sizeof(buffer), stdin);

    //4.输出读取结果到标准输出（相当于我们自己定义的缓冲区写入到了输出缓冲区中，最后 C 会帮助我们刷新的）
    printf("%s", buffer);

    //5.关闭被打开的文件
    close(fd);
    return 0;
}