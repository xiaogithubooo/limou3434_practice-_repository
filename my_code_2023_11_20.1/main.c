#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h> 
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM 1024
char cmd_line[NUM];//保存完整命令字符串

#define SIZE 32
char* g_argv[SIZE];//保存打散后的命令字符串，是一个数组

#define SEP " "//分隔符

char cwd[1024];//设置pwd环境变量
char new_env[1024];//设置新增加的环境变量
int lats_code = 0;//最近一次

const char* GetUserName(void)//获取用户名字
{
    const char* userName = getenv("USER");
    if(userName) 
        return userName;
    else
        return "none";
}

const char* GetHostName(void)//获取主机名字
{
    const char* hostName = getenv("HOSTNAME");
    if(hostName)
        return hostName;
    else
        return "none";
}

const char* GetPwd(void)//获取路径地址
{
    const char* pwd = getenv("PWD");
    if(pwd)
        return pwd;
    else
        return "none";
}

void Print(void)//打印提示信息
{
    printf("[%s@%s %s]$ ", GetUserName(), GetHostName(), GetPwd());
    fflush(stdout);
}

bool GetUserCommand()//获取 user 的输入
{
    memset(cmd_line, '\0', sizeof(cmd_line));//设定初始值
    if(fgets(cmd_line, sizeof(cmd_line), stdin) == NULL)//获取字符串，不能使用 scanf()
    {
        //出错就直接跳出循环
        return false;
    }
    cmd_line[strlen(cmd_line) - 1] = '\0';//将用户输入的字符串去掉 \n
    if(strlen(cmd_line) == 0)
        return false;
    return true;
}

void AnalyzeStr(void)//命令行字符解析
{
    //虽然可以自己写一个算法解析，但是我们可以使用一些现有的接口
    g_argv[0] = strtok(cmd_line, SEP);//第一次调用需要传入原始字符串和分隔符

    int index = 1;

    //处理特殊的命令情况
    if(strcmp(g_argv[0], "ls") == 0)//如果输入的命令是 ls 就进行一些特殊处理
    {
        g_argv[index++] = "--color=auto";//增加颜色参数，让输出带有颜色
    }

    while(g_argv[index++] = strtok(NULL, SEP));//第二次还想要解析原始字符串，就需要传入 NULL
}

bool DoBuildin()//处理内建命令
{
    //内建命令 cd
    if(strcmp(g_argv[0], "cd") == 0)   
    {   
        printf("父进程 run:\n");
        //更改路径的命令
        char* path = NULL;
        if(g_argv[1] == NULL)
        {
            path = ".";
        }
        else
        {
            path = g_argv[1];
        }
        chdir(path);
        
        char tmp[1024];
        getcwd(tmp, sizeof(tmp));//获取当前进程所在的地址（工作目录）
        sprintf(cwd, "PWD=%s", tmp);//组合环境变量
        putenv(cwd);//设置环境变量
        return true;
    }
    //内建命令 export
    if(strcmp(g_argv[0], "export") == 0)
    {
        if(g_argv[1] == NULL) return false;
        strcpy(new_env, g_argv[1]);
        putenv(new_env);
        return true;
    }
    //内建命令 echo
    if(strcmp(g_argv[0], "echo") == 0)
    {
        if(*g_argv[1] == '$')//特殊命令（查找环境变量和打印最近一次进程的返回值）
        {
            char* val = g_argv[1] + 1;//这个指针指向的就是 $PATH 或者 $? 中的 PATH 和 ?
            
            if(strcmp(val, "?") == 0)//查看退出码
            {
                printf("%d\n", lats_code);
                lats_code = 0;
            }
            else//查看环境变量
            {
                printf("%s\n", getenv(val));
            }
        }
        else//一般命令（如果不是特殊的命令就直接退出交给后续的程序替换即可）
        {
            return false;
        }
        return true;
    }
    return false;
}

void RunCommand(void)//fork() 创建子进程，execvp() 替换子进程
{
    pid_t id = fork();
    if(id == 0)//child
    {
        printf("子进程 run:\n");
        execvp(g_argv[0], g_argv);//自动在环境变量中搜索 g_argv[0] 的文件，执行 g_argv 数组存储的指令
        exit(1);//没替换成功就会异常退出
    }
    else
    {
        //father
        int status = 0;
        pid_t ret = waitpid(id, &status, 0);//阻塞等待
        if(ret > 0) 
        {
            lats_code = WEXITSTATUS(status);//最近一次运行子进程的退出码
        }
    }
}

int main()
{
	while(1)
    {
        //1.打印提示信息
        Print();
    
        //2.获取 user 的输入
        if(!GetUserCommand())
            continue;

        //3.命令行字符解析
        AnalyzeStr();

        //4.处理内建命令
        if(DoBuildin())
            continue;

        //5.fork() 创建子进程，execvp() 替换子进程
        RunCommand();
    }
    return 0;
}
