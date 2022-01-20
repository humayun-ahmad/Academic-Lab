#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <sched.h>
#include <stdlib.h>

pthread_mutex_t key;


void X(){
	pthread_mutex_lock(&key);
	pid_t pid,threadIDX;
	int cpuNo;
	
	threadIDX = syscall(SYS_gettid);
	cpuNo = sched_getcpu();
	pid = getpid();
	cpu_set_t cs;
	
	printf("ThreadIDX : %d,cpuNo : %d,PID : %d,CPU_affinity : %d\n", threadIDX,cpuNo,pid, sched_getaffinity(0,sizeof(cs), &cs));
	
	pthread_mutex_unlock(&key);

}

void Y(){
	pthread_mutex_lock(&key);
	pid_t pid,threadIDY;
	int cpuNo;
	
	threadIDY = syscall(SYS_gettid);
	cpuNo = sched_getcpu();
	pid = getpid();
	cpu_set_t cs;
	
	printf("ThreadIDY : %d,cpuNo : %d,PID : %d,CPU_affinity : %d\n", threadIDY,cpuNo,pid, sched_getaffinity(0,sizeof(cs), &cs));
	
	pthread_mutex_unlock(&key);

}

int main(){
	pid_t pid,threadID;
	pthread_t tid1,tid2,tid3;
	int cpuNo;
	threadID = syscall(SYS_gettid);
	cpuNo = sched_getcpu();
	cpu_set_t cs;
	
	pthread_create(&tid1, NULL, (void *) X, NULL);
	pthread_create(&tid2, NULL, (void *) Y, NULL);
	
	/* X thread */
	for(int i = 0; i < 10; i++){
		printf("Main Thread of process BlackHole\n");	
	}
	
	
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	return 0;
}
