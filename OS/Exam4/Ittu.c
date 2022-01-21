#define _GNU_SOURCE
#include <stdio.h>
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <sys/shm.h>

int main(int argn,char *argv[]){
	int a,b;
	
	//a = argv[0];
	//b = argv[1];
	//printf("Hello :)\n");
	//printf("%s %s\n", argv[1], argv[2]);
	
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	
	printf("Interger value of x : %d\nInteger value of y : %d\n", x,y);
	
	
	int result = x + y;
	
	printf("Result : %d\n", result);
	
	//printf("Hello\n");
	//printf("value of a : %d\nvalue of b: %d\n", a, b);
	//printf("Result : %d\n", a+b);
	
	key_t shmKey;
	int shmID;
	char *str;
	
	shmKey = ftok("testfile", 'o');
	//printf("SHM_key: %d\n", shmKey);
	
	
	
	shmID = shmget(shmKey, 100, IPC_CREAT | 0666);
	str = (char *) shmat(shmID, NULL, 0);
	
	//covert integer to string
	
	//char *st = result + '0';
	
	sprintf( str, "%d", result);
	
	//itoa(result,str,10);
	
	//strcpy(str, st);
	
	return 0;
}
