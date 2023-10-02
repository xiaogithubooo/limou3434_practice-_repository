//myshell.c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define NUM 1024
#define SIZE 32
#define SEP " "
char cmd_line[NUM];//保存完整命令字符串
char* g_argv[SIZE];//保存打散后的命令字符串

#define INPUT_REDIR 1//输入重定向
#define OUTPUT_REDIR 2//输出重定向
#define APPEND_REDIR 3//追加重定向
#define NONE_REDIR 0

int redir_status = NONE_REDIR;
char* Checkredir(char* cmd_str)//查找重定向符号
{
    assert(cmd_str);
    char* end = cmd_str + strlen(cmd_str) - 1;//例如"abcd\0"，end->'\0'
    while (end >= cmd_str)
    {
        if (*end == '>')
        {
            if (*(end - 1) == '>')
            {
                //追加重定向
                redir_status = APPEND_REDIR;
                *(end - 1) = '\0';//例如"ls -a -l>>mytext.txt"，end->后一个'>'，end-1->前一个'>'，将前面的命令分割为单独的字符串
                end++;//此时end->'m'
                break;
            }
            //输出重定向
            redir_status = OUTPUT_REDIR;
            *end = '\0';//例如"la -a -l>mytext.txt"，end->'>'，将前面的命令分割为单独的字符串
            end++;//end->'m'
            break;
        }
        else if (*end == '<')
        {
            redir_status = INPUT_REDIR;
            *end = '\0';
            end++;
            break;
        }
        end--;
    }
    if (end >= cmd_str)
    {
        return end;//返回要打开文件
    }
    else
    {
        return NULL;//说明没有找到重定向符号，直接返回NULL
    }
}
int main()
{
    while (1)
    {
        //1.打印提示信息
        printf("[user@myshell]$ ");
        fflush(stdout);
        memset(cmd_line, '\0', sizeof(cmd_line));
        //2.获取user的输入
        if (fgets(cmd_line, sizeof(cmd_line), stdin) == NULL)
        {
            //出错处理
            continue;
        }
        cmd_line[strlen(cmd_line) - 1] = '\0';
        
        char* sep = Checkredir(cmd_line);//分析是否有重定向符号

        //3.命令行字符解析
        //虽然可以自己写一个算法解析，但是我们可以一些现有的接口
        g_argv[0] = strtok(cmd_line, SEP);//第一次调用需要传入原始字符串

        int index = 1;
        if (strcmp(g_argv[0], "ls") == 0)
        {
            g_argv[index++] = "--color=auto";
        }
        while (g_argv[index++] = strtok(NULL, SEP));//第二次还想要解析原始字符串，就需要传入NULL
        //4.TODO                                                
        //需要判断命令，如果是cd这样的命令不能使用子进程
        if (strcmp(g_argv[0], "cd") == 0)
        {
            printf("下面功能让父进程来\n");
            //更改路径的命令
            if (g_argv[1] != NULL) chdir(g_argv[1]);
            continue;
        }
        //5.fork()一个子进程
        pid_t id = fork();
        if (id == 0)//child
        {
            if (sep != NULL)
            {
                //找到重定向符号，并且返回的sep保存了重定向的文件
                int fd = -1;//因为switch内部不可以定义变量，所以搬到外面先定义了
                switch (redir_status)//确认重定向的状态
                {
                case INPUT_REDIR:
                    break;
                case OUTPUT_REDIR:
                    fd = open(sep, O_WRONLY | O_TRUNC | O_CREAT, 0666);
                    dup2(fd, 1);//重定向
                    break;
                case APPEND_REDIR:
                    break;
                default:
                    printf("There is bug.\n");
                    break;
                }
            }
            printf("子进程run：\n");
            execvp(g_argv[0], g_argv);
            exit(1);
        }
        //father
        int status;
        pid_t ret = waitpid(id, &status, 0);
        if (ret > 0) printf("exit code: %d\n", WEXITSTATUS(status));
    }
    return 0;
}
