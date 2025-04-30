/*NAME - Shipra Pal
REGISTRATION NO.-2141016019

Inter-Process Communication (IPC) Using Shared Memory
Implement an IPC mechanism using shared memory in C:
Create a shared memory segment and attach it to the process's memory space.
Write a string message to the shared memory in one process.
Read and display the message from the shared memory in another process.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define SHM_SIZE 1024  
#define SHM_KEY 1234

int main()
{
	int shmid;
	char *shm_ptr;
    
	shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);

	shm_ptr = (char *) shmat(shmid, NULL, 0);
    
	const char *mess = "Hello from Shipra Pal !";
	strncpy(shm_ptr, mess, SHM_SIZE);
	printf("Writer wrote: %s\n", mess);
	shmdt(shm_ptr);

	return 0;
}
