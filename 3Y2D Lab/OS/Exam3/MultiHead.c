#include <stdio.h>

#include <unistd.h>

#include <pthread.h>

#include <assert.h>

#include <stdlib.h>
int result;

struct thread_args *args = malloc (sizeof (struct thread_args));

void Ittu(void *_args){
	struct thread_args *args = (struct thread_args *) _args;

  	printf ("The sum is : %d\n", args->first + args->second);

  	

	//printf("I'm from Bittu for Subtraction\n");

	

	free (args);

  	pthread_exit (NULL);

}





void Bittu(void *_args){

	

	struct thread_args *args = (struct thread_args *) _args;

	

  	printf ("The subtraction is : %d\n", args->first - args->second);

  	

	printf("I'm from Bittu for Subtraction\n");

	

	free (args);

  	pthread_exit (NULL);

}





void Mittu(void *_args){

	

	struct thread_args *args = (struct thread_args *) _args;

	

  	printf ("The Multiplication is : %d\n", args->first * args->second);

  	

	printf("I'm from Bittu for Subtraction\n");

	

	free (args);

  	pthread_exit (NULL);

}



int main(){

	pthread_t tid1,tid2,tid3;

	

	int value = 5;

	

	

	args->first = 5;

	args->second = 10;

	

	//pthread_create(&tid1, NULL, (void *) Ittu, &value);

	assert (pthread_create(&tid1, NULL, (void *) Ittu, args) == 0);

	assert (pthread_create(&tid2, NULL, (void *) Bittu, args) == 0);

	assert (pthread_create(&tid3, NULL, (void *) Mittu, args) == 0);

	//pthread_create(&tid3, NULL, (void *) Mittu, NULL);

	

	

	for(int i = 0; i < 5; i++){

		printf("Main thread\n");

	}



	pthread_join(tid1, NULL);

	pthread_join(tid2, NULL);

	pthread_join(tid3, NULL);

	

	return 0;

}