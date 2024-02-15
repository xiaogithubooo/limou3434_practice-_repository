#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
    //打开文件，如果文件不存在则创建，以读写模式打开
    FILE *file = fopen("bite", "w+");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    //向文件中写入内容
    const char *content = "linux so easy!";
    fwrite(content, sizeof(char), strlen(content), file);

    //将文件指针移动到文件开头
    fseek(file, 0, SEEK_SET);

    //读取文件内容并打印到标准输出
    char buffer[1024];
    size_t bytesRead = fread(buffer, sizeof(char), sizeof(buffer), file);
    if (bytesRead > 0)
    {
        printf("%s\n", buffer);
    }
    else
    {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }

    //关闭文件流
    fclose(file);

    return 0;
}
