#include <stdio.h>
#include <stdlib.h>
#include <minix/syslib.h>
#include <lib.h>    // provides _syscall and message
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int signo)
{
  return;
}

int call_sem(int id, int action)
{
	message m;

	m.m1_i1 = id;
 	m.m1_i2 = getpid();

 	return _syscall(PM_PROC_NR, action, &m);
}

int sem_create(int id)
{
 	return call_sem(id, PM_SEM_CREATE);
}

int sem_terminate(int id)
{
	return call_sem(id, PM_SEM_TERMINATE);
}

int sem_down(int id)
{

  signal(SIGCONT, sig_handler);

  int success;

  success = call_sem(id, PM_SEM_DOWN);

  while (success == 1) {
    pause();
    printf("ay pero que dolor");
    success = call_sem(id, PM_SEM_DOWN);
  }

  return success;
}

int sem_up(int id)
{
	return call_sem(id, PM_SEM_UP);
}


int main(int argc, char **argv)
{
	if(argc < 1)
		return 1;

 	int sem = atoi(argv[1]);

 	fork();

 	pid_t pid = getpid();

 	sem_create(sem);

 	sem_down(sem);

 	for(int i =1; i<11; i++)
 	{
 		printf("\nProcess %d working second: %d", pid, i);
 		sleep(1);
 	}
 	printf("\nProcess %d Finished\n", pid);

 	sem_up(sem);


}
