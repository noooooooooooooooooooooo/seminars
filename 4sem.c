#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <fcntl.h>

int main(int argc, char *argv[], char *envp[]) {
	int fd = open("file", O_RDWR, 0666);
	dup2(fd, 0);
	execle("/bin/grep", "grep", "bin", "file", NULL, envp);	
	close(fd);
	return 0;
}