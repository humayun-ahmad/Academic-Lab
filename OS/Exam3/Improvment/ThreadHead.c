/***


QUESTION:

Create a process, named MultiHead, having three threads, named Ittu, Bittu, and Mittu .

Ittu, Bittu, and Mittu  perform addition, subtraction and multiplication of two variables sent by the main thread of the process and keep the output in a global variable, result. All threads print their process ID, thread ID, CPU Info and the global variable, 'result'.



1. The main thread waits until each thread finish its task.



2. The main thread reads and sends two integer values to each thread 100 times.



3. If any thread finds that 'result' = 100, it immediately send signal to the main thread to stop the process.



Take necessary steps to avoid thread racing.



***/



#define _GNU_SOURCE

#include <stdio.h>

#include <unistd.h>

#include <pthread.h>

#include <assert.h>

#include <stdlib.h>

#include <sys/syscall.h>

#include <sched.h>





int result;





struct numbers{

	int a;

	int b;

};









void *Ittu(void *_args){

	

	struct numbers *args = (struct numbers *) _args;

  	pid_t pid,threadID;

  	int cpuNo;

  	

  	

  	result = args->a + args->b;

  	pid = getpid();

  	threadID = syscall(SYS_gettid);

  	//cpuNo = sched_getcpu();

  	cpuNo = sched_getcpu();

  	if(result == 100){

  		//pid = getpid();

  		//kill(pid, SIGQUIT);

  	}

  	

  	printf("The sum is : %d and ProcessID : %d threadID : %d  and It is running at CPU-%d\n", result,pid,threadID,cpuNo);

  	

}





void *Bittu(void *_args){

	

	struct numbers *args = (struct numbers *) _args;

	pid_t pid,threadID;

  	int cpuNo;

  	

  	

  	result = args->a - args->b;

  	pid = getpid();

  	threadID = syscall(SYS_gettid);

  	//cpuNo = sched_getcpu();

  	cpuNo = sched_getcpu();

  	

  	if(result == 100){

  		//pid = getpid();

  		//kill(pid, SIGQUIT);

  		//exit(1);

  	}

  	

  	printf("The sum is : %d and ProcessID : %d threadID : %d  and It is running at CPU-%d\n", result,pid,threadID,cpuNo);

  	

}





void *Mittu(void *_args){

	

	struct numbers *args = (struct numbers *) _args;

	

	pid_t pid,threadID;

  	int cpuNo;

  	

  	

  	result = args->a * args->b;

  	pid = getpid();

  	threadID = syscall(SYS_gettid);

  	//cpuNo = sched_getcpu();

  	cpuNo = sched_getcpu();

  	

  	if(result == 100){

  		//pid = getpid();

  		//kill(pid, SIGQUIT);

  	}

  	

  	printf("The sum is : %d and ProcessID : %d threadID : %d  and It is running at CPU-%d\n", result,pid,threadID,cpuNo);

	

  	

}	



int main(){

	pthread_t tid1,tid2,tid3;

	

	printf("Main Thread\n");

	

	struct numbers *args = malloc(sizeof(struct numbers));

	

	

	for(int i = 1; i <= 100; i++){

		int x,y;

		scanf("%d", &x);

		scanf("%d", &y);

		

		args->a = x;

		args->b = y;

		

		//pthread_create(&tid3, NULL, (void *) Mittu, NULL);

		pthread_create(&tid1, NULL, (void *) Ittu, args);

		pthread_create(&tid2, NULL, (void *) Bittu, args);

		pthread_create(&tid3, NULL, (void *) Mittu, args);

		



		pthread_join(tid1, NULL);

		pthread_join(tid2, NULL);

		pthread_join(tid3, NULL);

	}

	

	

	free (args);

	

	return 0;

}