#include <stdio.h>
#include <stdlib.h>
#include <minix/syslib.h>
#include <lib.h>    // provides _syscall and message
 
int main(int argc, char **argv)
{
 
 	message m

 	int i = _syscall(PM_PROC_NR, PM_GETDATE, &m);

 	printf("Syscall equals %d", i);
 	
    return 0;
}