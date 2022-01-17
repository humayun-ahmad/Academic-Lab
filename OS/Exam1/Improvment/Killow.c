#define _GNU_SOURCE

#include <stdio.h>

#include <unistd.h>

#include <sched.h>





int main(){

	pid_t ppid;

	int cpu;

	while(1){

		ppid = getpid();

		cpu = sched_getcpu();

		//ppid = getppid();

		printf("I am child-%u running at CPU-%d\n", ppid, cpu);

	}

	

	return 0;

}