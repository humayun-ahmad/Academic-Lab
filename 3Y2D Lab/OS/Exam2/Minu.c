#include <stdlib.h>

#include <unistd.h>

#include <stdio.h>

#include <string.h>

#include <sys/stat.h>

#include <sys/types.h>

#include <fcntl.h>



int main(int argc, char *argv[]){

	int fd;

	

	// location of my file, define file path.

	char myFilePath[200] = "/home/humayun/Desktop/Class_work/Exam_code/Exam2/";

	strcat(myFilePath, argv[1]);

	

	

	char mst1[30],mst2[30],mst3[30];

	

	

		

		

	while(1){

		/*

		fd = open(myFilePath, O_RDONLY);

		read(fd,mst3,sizeof(mst3));

		if(!strcmp(mst3,"Bye")){

			break;

		}

		close(fd);

		*/

		fd = open(myFilePath, O_WRONLY); // file open into the write mood

		

		//printf("FD value of Minu: %d\n", fd);

		//fgets(mst2,30,stdin); // taking input from the Minu

		scanf("%s", mst2);

		write(fd, mst2, strlen(mst2)+1);

        	close(fd);

        	if(!strcmp(mst2,"Bye")){

        		break;

        	}

	}



	return 0;

}