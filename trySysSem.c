#include <stdio.h>
#include <stdlib.h>
#include <minix/syslib.h>
#include <lib.h>    // provides _syscall and message

int main(int argc, char **argv)
{
	if(argc < 1)
		return 1;
int sem, option, result;
message m;


/*
m.m1_i1 = atoi(argv[1]);

printf("Argument to send %d", atoi(argv[1]));

result = _syscall(PM_PROC_NR, PM_SEM_CREATE, &m);

printf("\nSyscall create equals %d", result);

m.m1_i1 = 1 //atoi(argv[1]);

result = _syscall(PM_PROC_NR, PM_SEM_DOWN, &m);

printf("\nSyscall down equals %d", result);

result = _syscall(PM_PROC_NR, PM_SEM_CREATE, &m);

printf("\nSyscall create equals %d", result);
*/

printf("\nActions: 1 create, 2 down, 3 up, 4 delete, 0 exit.\nSems: 2-30; 1 is reserved.");

while (option != 0)) {
  m.m1_i1 = 1 //atoi(argv[1]);
  result = _syscall(PM_PROC_NR, PM_SEM_DOWN, &m);

  printf("\nNow chose the next step (sem,action):");
  scanf("%i,%i\n", sem, option);

  m.m1_i1 = 1 //atoi(argv[1]);
  result = _syscall(PM_PROC_NR, PM_SEM_UP, &m);

  switch(option) {
    case 1 :
      m.m1_i1 = sem;
      result = _syscall(PM_PROC_NR, PM_SEM_CREATE, &m);
      break;
  	case 2 :
      m.m1_i1 = sem;
      result = _syscall(PM_PROC_NR, PM_SEM_DOWN, &m);
      break;
    case 3 :
      m.m1_i1 = sem;
      result = _syscall(PM_PROC_NR, PM_SEM_UP, &m);
      break;
    case 4 :
      m.m1_i1 = sem;
      result = _syscall(PM_PROC_NR, PM_SEM_TERMINATE, &m);
      break;
    default :
      break;
  }
}
    return 0;
}
