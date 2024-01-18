#pragma noce
#define BUFFER_SIZE 4096
#define FLUSH_NONE 1
#define FLUSH_LINE (1 << 1)
#define FLUSH_ALL (1 << 1)

typedef struct MyFILE
{
    int _fileno;                    //文件描述符
    int _flag;                      //刷新策略标记
    char _buffer[BUFFER_SIZE];      //缓冲区
    int _end;                       //end - 0 为缓冲区大小
} MyFILE;

MyFILE* Myfopen(const char* path, const char* mode);
int Mywrite(const char* s, int num, MyFILE* stream);
int Myfflush(MyFILE* stream); 
int Myfclose(MyFILE* stream);