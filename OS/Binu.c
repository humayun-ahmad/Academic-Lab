#include <stdlib.h>

#include <unistd.h>

#include <stdio.h>

#include <string.h>

#include <sys/stat.h>

#include <sys/types.h>

#include <fcntl.h>



int main(){

	int fd1;

	

	//define file path/location

	char *myFilePath = "/home/humayun/Desktop/Class_work/Exam_code/Exam2";

	

	

	mkfifo(myFilePath, 0666); // namde file is created here.

	

	char bst1[30],bst2[30];

	

	while(1){

		fd1 = open(myFilePath, O_RDONLY);

		

		read(fd1,bst1,30); // Minu's message will be reading here

		

		if(!strcmp(bst1,"bye")){

			break;

		}else{

			printf("Minu : %s\n", bst1);

		}

        	close(fd1);

		

	}



	return 0;

}