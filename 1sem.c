#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main(int argc, char *argv[], char *envp[]) {
	pid_t pid;
	pid = fork();
	if(pid == 0) {
		execle("/bin/ls", "ls", "-la", NULL, envp);
	}
	else if(pid < 0) {
		printf("oops!");
		return 0;
	}
	else {
		printf("Hello world!");
	}
	return 0;
}