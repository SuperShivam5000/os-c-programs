#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
    int n = getpid();
    printf("parent of all %d \n",n);
    pid_t p; 
    p = fork();
    if(p==0){
    fork();
    fork();
    fork();
    }
    if(p==0){
    int s = getppid();
    printf(" child with id: %d and its parent id: %d\n",s,n);
    return p;
    }
return 0;
}