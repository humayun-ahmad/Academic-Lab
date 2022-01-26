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

int main(){
	pid_t child_a, child_b,child_c,pid, ppid,kpid,mpid;
	int cpu;
	
	key_t shmKey;
	int shmID;
	char *str;
	
	shmKey = ftok("testfile", 'o');
	//printf("SHM_key: %d\n", shmKey);
	
	
	shmID = shmget(shmKey, 100, IPC_CREAT | 0666);
	str = (char *) shmat(shmID, NULL, 0);
	
	child_a = fork();
	int a = 5,b = 5;
	
	char ch1[200] = "10";
	char ch2[200] = "20";
	
	if (child_a == 0) {
	    /* Child a code */
	    
	    execlp("./Ittu", "./Ittu", ch1, ch2, NULL);
	    printf("Result : %s\n", str);
	} else {
	    child_b = fork();

	    if (child_b == 0) {
		/* Child b code */
		//printf("child_b\n");
		execlp("./Bittu", "./Bittu", ch1, ch2, NULL);
	    } else {
		/* child c Code */
		child_c = fork();
		
		if(child_c == 0){
			//printf("child_c\n");
			execlp("./Mittu", "./Mittu", ch1, ch2, NULL);
		}else{
			/* parent */
			printf("parent\n");
		}
		
	    }
	}
	return 0;
}
