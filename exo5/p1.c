# include <sys/types.h> 
# include <unistd.h>
# include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define PATH "/home/akane/Desktop/miniProjet/exo5/tube1"
#define PATH1 "/home/akane/Desktop/miniProjet/exo5/tube3"
int main(int argc,char *argv[]){
FILE *fic;
int i;
char filerecup[80], res[20];
char op;
int num1, num2;
fic=fopen(PATH,"w");
if(fic<0)
{
perror("probleme fopen()\n");
exit(1);
}
for(i=1;i<argc;i++){
fputs(argv[i],fic);
if(i != argc - 1){
fputs(" ", fic);
}
}
fclose(fic);
FILE *tube = fopen(PATH1, "r");
if(tube){
	while(fgets(filerecup, 80, tube)){
		printf("%s", filerecup);
		fclose(tube);
	}
}
else{
	perror("le tube n'exsite pas");
	exit(EXIT_FAILURE);
}
}


