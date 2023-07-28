#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main()
{
	//fork之前是父进程
	printf("进程PID：%d 父进程PPID：%d\n", getpid(), getppid()); 
	pid_t id = fork();
	//从这里以后父子进程的代码都是共享的，会根据if来做调整，因此共享和执行是两回事
	if(id < 0)
	{
		//进程创建失败
		perror("fork");
		return 1;
	}
	else if(id == 0)
	{
		//子进程
		while(1)
		{
			printf("I am child,PID:%d PPID:%d\n", getpid(), getppid());
			sleep(3);
		}
	}
	else
	{
		//父进程
		while(1)
		{
			printf("I am father,PID:%d PPID:%d\n", getpid(), getppid()); 
			sleep(1);
		}
	}
	printf("you can see me!\n");
	sleep(1);
	return 0;
}

