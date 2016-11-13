#include <stdio.h>
#include <stdlib.h>
#include <minix/syslib.h>
#include <lib.h>    // provides _syscall and message
 
int main(int argc, char **argv)
{
	if(argc < 1)
		return 1;
 
 	message m;

 	m.m1_i1 = atoi(argv[0]);

 	printf("Argument to send %d", atoi(argv[0]));

 	int i = _syscall(PM_PROC_NR, PM_SEM_CREATE, &m);

 	printf("\nSyscall create equals %d", i);

 	i = _syscall(PM_PROC_NR, PM_SEM_DOWN, &m);

 	printf("\nSyscall down equals %d", i);

 	i = _syscall(PM_PROC_NR, PM_SEM_CREATE, &m);

 	printf("\nSyscall createequals %d", i);

    return 0;
}