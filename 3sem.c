#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int fd[2];
	char b[17];
	int res;
	if(pipe(fd) < 0){
		printf("Can't create pipe\n");
		return -1;
	}
	pid_t pid;
	pid = fork();
	char a[17];
	if(pid > 0) {
		int cheslo;
		scanf("%d", &cheslo);
		sprintf(a, "%d", cheslo);
		write(fd[1], a, sizeof(int));
		
	}
	else if(pid == 0) {
		wait(NULL);
		read(fd[0], b, sizeof(int));
		sscanf(b, "%d", &res);
		printf("%d", 10*res);

	}
	else {
		printf("oshibka!!!");
	}
	return 0;
}