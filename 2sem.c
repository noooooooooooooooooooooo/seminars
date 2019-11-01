#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
	int fd = open(argv[1], O_RDWR, 0666);
	pid_t pid;
	char a[17];
	for(int i = 0; i < 3; i++) {
		pid = fork();
		if (pid > 0) {
			sprintf(a, "%d", pid);
			write(fd, a, sizeof(int));
		}
	}
	return 0;
}