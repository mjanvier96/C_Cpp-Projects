#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char *buff = malloc(3 * sizeof(char));
	int fd, num, fd_sol;
        char *cipherFile = "encrypted.txt";
	char *sol = "solution.txt";
	
	if((fd = open(cipherFile, O_RDONLY)) < 0){
                printf("Error opening Cipher");
                exit(1);
   	}

        if((fd_sol = open(sol, O_WRONLY)) < 0){
                printf("Error opening solution");
                exit(1);
        }
	
/*	while(1 != 2){
		if(num = read(fd, buff, 1024) < 0){
			printf("Error Reading cipher");
			exit(1);
		
		if(num = write(fd_sol, buff, 1024)){
			printf("Error writnig file");
			exit(1);
		}

		if(offest = lseek(fd, , ) < 0){

		}
	}*/
	return 0;
}
