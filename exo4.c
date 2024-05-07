#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char message[15] = "ramadan karim";
void reverse_string(char *str) {
    int len = strlen(str);
    for (int j = 0, i = len; j < i; j++, i--) {
        char tmp = str[j];
        str[j] = str[i];
        str[i] = tmp;
    }
    str[len+1] = '\0';
}

int main(){
	int p1[2], p2[2];
	int pipe(int[2]);
	if(pipe(p1) == -1 || pipe(p2) == -1 ){
		fprintf(stderr, "erreur ouverture pipe\n");
		exit(1);
	}
	if(fork() == 0) {// fils
		char messagerecu[14];
		char c;
		int nboctets;
		close(p1[1]);//close writing
		close(p2[0]);//close reading;
		read(p1[0], &c, 1) != 0;
		nboctets = read(p1[0], messagerecu, 14);
		printf("Lecture %d octets: %s\n", nboctets, messagerecu);
		reverse_string(messagerecu);
		//send the reversed message
		write(p2[1], messagerecu, nboctets);
		close(p1[0]);
		close(p2[1]);
		exit(0);
	}
	else{
		//suite pere
		close(p1[0]);//close reading
		close(p2[1]);//close writing
		write(p1[1], message, 15);
		char rev_msg[14];
		char c;
		int nboct;
		read(p2[0], &c, 1) != 0;
		nboct = read(p2[0], rev_msg, 14);
		printf("Lecture %d octets: %s\n", nboct, rev_msg);
		close(p1[1]);
		close(p2[0]);
		exit(0);
	}
}
