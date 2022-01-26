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

	    /* Child Pillow code */

	    execlp("/home/humayun/Desktop/Class_work/Exam_code/Exam1/Pillow", "Pillow", NULL);

	} else {

	    child_b = fork();



	    if (child_b == 0) {

		/* Child killow code */

		execlp("/home/humayun/Desktop/Class_work/Exam_code/Exam1/Killow", "Killow", NULL);

	    } else {

		/* Millow Code */

		while(1){

			mpid = getpid();

			cpu = sched_getcpu();

			printf("Process-%u, parent of Pillow-%u and Killow-%u, running at CPU-%d.\n", mpid,child_a,child_b,cpu);

	    	}

	    }

	}

	

	return 0;

}