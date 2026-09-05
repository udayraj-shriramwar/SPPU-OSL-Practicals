#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXSIZE 27
int main() {
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    key = 5679;

    shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        printf("Error: shmget failed\n");
        exit(1);
    }

    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        printf("Error: shmat failed\n");
        exit(1);
    }

    s = shm;

    for (c = 'a'; c <= 'z'; c++)
        *s++ = c;

    printf("\n\nServer is Ready!!\n");
    printf("Now data is available on shared memory!!\n");

    while (*shm != '*')
        sleep(1);

    printf("\n\nServer Terminated!!!\n\n");

    return 0;
}








