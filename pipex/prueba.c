#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>


int main()
{
	char *const args[] = {"ls", "-la",NULL};
	char *const envp[] = { NULL };

	execve("/usr/bin/ls", args, envp);

	perror("execve");
	return (1);
}

// int	main()
// {
// 	__pid_t pid;
// 	int		pfd[2];

// 	pipe(pfd);

// 	printf(">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<< \n");
// 	printf("I am a main process before fork. MyPId is -> %d \n", getpid());
// 			// create a chid process (fork)
// 	pid = fork();
// 	printf("--------------------    --------------- \n");
// 	printf("I am main process after fork. My PID is -> %d \n", getpid());
// 	if (pid < 0)
// 	{
// 		fprintf(stderr, "Fork2 failed \n");
// 		return 1;
// 	}
// 	else if (pid == 0)
// 	{
// 		printf("I am the child process! my PID is %d  and my childs PID is %d \n ", getpid(), pid);
// 		close(pfd[0]);
// 		write(pfd[1], "hola holita vecinitosss", 24);
// 		close(pfd[1]);
// 			exit(EXIT_SUCCESS);
// 	}
// 	else
// 	{
// 		printf("I am the parent process, and my PID is %d, and the childs is %d \n", getpid(), pid);
// 		char str[24];
// 		close(pfd[1]);
// 		read(pfd[0], str, 24);
// 		printf("parent received --> %s \n", str);
// 		close(pfd[0]);
// 		wait(NULL);
// 	}
// 	return 0;
// }
