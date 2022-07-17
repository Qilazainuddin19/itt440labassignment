#include<stdio.h>
	#include<unistd.h>
	#include<sys/wait.h>
	#include<stdlib.h>
	#include<math.h>
	#include<signal.h>
	#include<errno.h>
	

	void sigint_handler(int sig){
		printf("Program Interrupted!\n");
	}
	

	int Checker(int n){	//THIS IS PARENT
		int flag=0;
		for(int x = 2; x<=n/2 ;x++){
			x= n % 2;
			if(n%x==0){
				flag=1;
				break;
			}
		}
		return flag;
	}
	

	int Insert(){	//THIS IS CHILD
		int n; 
	   
	    printf("Enter a number: \n"); 
	   
	    scanf("%d", &n); 
	  
	    return n; 
	}
	

	int main(void){
		int flag;
		int z;
		if(signal(SIGINT,sigint_handler)==SIG_ERR){
			perror("signal");
			exit(1);
		}
		for(int y = 0; y < 1; y++){
			pid_t pid = fork();
			
			if(pid==0){
				z=Insert();
				exit(EXIT_SUCCESS);
			}
			else{
				printf("Checking...\n");
				wait(NULL);
			}
		}
		flag = Checker(z);
		if (flag == 0) { 
	        printf("It is a prime number.\n"); 
	    } 
	    else { 
	        printf("It is not a prime number.\n"); 
	    } 
		return 0;
	}
