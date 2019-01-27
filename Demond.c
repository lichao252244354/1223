#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(void)
{
	pid_t pid,sid;
	pid = fork();
	if(pid > 0)
	{
		return 0;
	}
	sid = setsid();
	int reval = chdir("/home");
	if(reval != 0)
	{
		perror("chdir falied");
		exit(1);
	}
	printf("sucess changed\n");
	umask(0002);
	close(STDIN_FILENO);
	int fd = open("/dev/null",O_RDWR);
	dup2(fd,STDOUT_FILENO);
	dup2(fd,STDERR_FILENO);
	while(1)
	{

	}


	return 0;
}
