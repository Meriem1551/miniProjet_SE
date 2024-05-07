# include <sys/types.h> 
 # include <unistd.h>
 # include <stdio.h> 
 #include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define PATH "/home/akane/Desktop/miniProjet/exo5/tube2"
#define PATH1 "/home/akane/Desktop/miniProjet/exo5/tube3"
int main(int argc, char *argv[]){
	char filerecup[80];
	char op;
	int num1, num2;
	if(mkfifo(PATH, 0644) == -1){
		perror("problem mkfifo()\n");
		exit(EXIT_FAILURE);
	}
	FILE *tube = fopen(PATH, "r");
	if(tube){
		while(fgets(filerecup, 80, tube)){
			printf("%s", filerecup);
			if(sscanf(filerecup, "%d %c %d", &num1, &op, &num2) == 3){
				FILE *fic;
				int i;
				fic=fopen(PATH1,"w");
				if(fic<0)
				{
					perror("probleme fopen()\n");
					exit(1);
				}
				fputs(num1+num2, fic);
				fclose(fic);
			}
			fclose(tube);
		}
	}
	else{
		perror("le tube n'exsite pas");
		exit(EXIT_FAILURE);
	}
	unlink(PATH);
	return EXIT_SUCCESS;
}
