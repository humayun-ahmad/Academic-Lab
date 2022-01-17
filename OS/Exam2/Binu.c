#include <stdlib.h>

#include <unistd.h>

#include <stdio.h>

#include <string.h>

#include <sys/stat.h>

#include <sys/types.h>

#include <fcntl.h>



int main(int argc, char *argv[]){

	int fd1;

	

	//define file path/location

	char myFilePath[200] = "/home/humayun/Desktop/Class_work/Exam_code/Exam2/";

	strcat(myFilePath,argv[1]);

	

	//mkfifo(myFilePath, 0666); // namde file is created here.

	

	char bst1[30],bst2[30];

	

	while(1){

		fd1 = open(myFilePath, O_RDONLY);

		

		read(fd1,bst1,sizeof(bst1)); // Minu's message will be reading here

		//printf("FD1 value of Binu: %d\n", fd1);

		if(!strcmp(bst1,"Bye")){

			printf("Bye\n");

			break;

		}else{

			printf("%s\n", bst1);

		}

		close(fd1);

        	//write(STDOUT_FILENO, bst1, 30);

        	//close(fd1);

        	//wait(1);

        	

        	/*

        	fd1 = open(myFilePath, O_WRONLY);

        	fgets(bst2,20,stdin); // Taking input from the Binu

        	write(fd1,bst2,strlen(bst2) + 1);

        	close(fd1);

		*/

	}

	

	return 0;

}