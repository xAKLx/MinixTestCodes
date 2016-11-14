#include <stdio.h>
#include <stdlib.h>
#include <minix/syslib.h>
#include <lib.h>    // provides _syscall and message
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if(argc < 1)
		return 1;
 
 	message m;

 	m.m1_i1 = atoi(argv[1]);

  printf("\nPid from test = %d", getpid());

 	printf("\nArgument to send %d", atoi(argv[1]));

 	int i = _syscall(PM_PROC_NR, PM_SEM_CREATE, &m);

    return 0;
}