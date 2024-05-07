#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
int i = 0, n;
printf("enter number of processes you want to create ");
scanf("%d", &n);
int x = fork();
while(x==0 && i < n){
printf("Le pid du fils %d\n", getpid());
printf("Le pid du pere %d\n", getppid());
x = fork();
i++;
}
exit(0);
}
