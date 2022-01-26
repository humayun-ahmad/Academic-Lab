#include <stdio.h>

#include <unistd.h>



int main(){

	int mPid,pPid,kPid;

	int id1,id2;

	/*mPid = fork();

	

	if(mPid != 0){

		pPid = fork();

		if(pPid != 0){

		

			printf("Process - %d , parent of Pillow - %d and %",kPid,pPid);

			

		}else{

			printf("");

		}

	}

	*/

	

	printf("\n");

	

	id1 = fork();

	id2 = fork();

	printf("Process-%d\n", id1);

	if(id1 == 0){

		int kpid = getpid();

		int ppid = getppid();

		printf("parent of Pillow-%d and Killow-%d, running at CPU-0\n", kpid,ppid);

		if(id2 == 0){

			int kpid = getpid();

			//int kppid = getppid();

			printf("\nI am child %d\n", kpid); //Killo

		}else{

			int pillowpid = getpid();

			printf("\nI am child %d\n", pillowpid); //Pillow

		}

	}else{

		if(id2 == 0){

			int mpid = getpid();

			printf("\nI am child %d\n",mpid); //Mellow

		}else{

			printf("\nthis is the parrent process");

		}

	}

	printf("\n");

	

	return 0;

}