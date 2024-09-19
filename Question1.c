// Question1.c

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int n = 0;

    pid_t pid;{
        printf("Enter a number other than 0...\n"); // collatz conjecture
        scanf("%d", &n); // input is n
    } 

    while(n <= 0);
    pid = fork();  // make child process

    if(pid == 0){
        printf("COMPLETING CHILD PROCESS...\n");
        printf("%d\n", n);  // print initial n value
        while(n != 1){  // continue until n = 1
            if(n % 2 == 0){ // if n is even
                n = n / 2;
            }
            else{ // if n is odd
                n = 3 * n + 1;
            }
            printf("%d\n", n);  // print updated n value
        }
        printf("CHILD PROCESS COMPLETED\n");
    }

    else if(pid > 0){  // parent process
        printf("PARENT PROCESS WAITS FOR CHILD COMPLETION...\n");
        wait(NULL);  // Wait for the child process to complete
        printf("PARENT PROCESS COMPLETED\n");
    }

    else{  // no child process 
        printf("FORK FAILURE\n");
        return 1;
    }

    return 0;
}
