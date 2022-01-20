#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <sys/wait.h>

int main(){
	pid_t child_a, child_b,pid, ppid,kpid,mpid;
	int cpu;
	child_a = fork();
	printf("\n");
	if (child_a == 0) {
	    /* Child Nebula code */
	    for(int i = 1; i <= 100; i++){
	    	execlp("./Nebula", "./Nebula", NULL);
	    }
	    
	} else {
	    child_b = fork();

	    if (child_b == 0) {
		/* Child BlackHole code */
		for(int i = 1; i <= 100; i++){
			execlp("./BlackHole", "./BlackHole", NULL);
		}
		
	    } else {
		/* Parent Code */
		
			mpid = getpid();
			cpu = sched_getcpu();
			printf("Process-%u, parent of Nebula-%u and BlackHole-%u, running at CPU-%d.\n", mpid,child_a,child_b,cpu);
	    	
	    }
	}
	
	return 0;
}
