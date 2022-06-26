#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childTask(){

	char name[10];
	printf("Enter name: \n ");
	fgets(name, 10, stdin);
	printf(" Name is: %s ", name);
	printf("Child process => PPID=%d, PID=%d\n", getppid(), getpid());
	exit(0);
	}

void parentTask(){

	printf(" Parent process => PID=%d\n ", getpid());
	printf(" Waiting for child process...\n  ");
	wait(NULL);
	printf("Job is done \n");
	}


	int main(void){

		for(int i = 0; i<4; i++){
		 pid_t pid = fork();

		if(pid == 0){
		childTask();
		}

		else if(pid > 0){
		parentTask();
		}
	}
	return(0);

	}
