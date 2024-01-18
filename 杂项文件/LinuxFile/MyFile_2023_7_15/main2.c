#include <stdio.h>
#include <unistd.h>
int main()
{
	pid_t id = fork();
	if(id == 0)
	{
		//child
		while(1)
		{
			printf("hello i am child\n");
			sleep(1);
		}
	}
	else
	{
		//fatcher
		int n = 6;
		while(n >= 0)
		{
			printf("hello i am fatcher\n %d", n);
			sleep(1);
			n--;
		}
	}
	return 0;
}
