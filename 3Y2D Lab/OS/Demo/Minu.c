#include <stdlib.h>

#include <unistd.h>

#include <stdio.h>

#include <string.h>

#include <sys/stat.h>

#include <sys/types.h>

#include <fcntl.h>



int main(){

	int fd;

	

	// location of my file, define file path.

	char *myFilePath = "/home/humayun/Desktop/Class_work/Exam_code/Exam2";

	

	mkfifo(myFilePath, 0666); // named file is created here.0666 number means that permission

	

	char mst1[30],mst2[30];

	

	while(1){

		

		fd = open(myFilePath, O_WRONLY); // file open into the write mood

		

		fgets(mst2,30,stdin); // taking input from the Minu

		

		write(fd, mst2, strlen(mst2)+1);

        	close(fd);

	}



	return 0;

}