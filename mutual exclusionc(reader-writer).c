#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_mutex_t wrt;
int readcount = 0;
int shared_data = 0;

void *reader(void *arg) {
    int id = *((int *)arg);
    pthread_mutex_lock(&mutex);
    readcount++;
    if (readcount == 1) {
        pthread_mutex_lock(&wrt);
    }
    pthread_mutex_unlock(&mutex);

    printf("Reader %d: read shared_data = %d\n", id, shared_data);
    sleep(1);

    pthread_mutex_lock(&mutex);
    readcount--;
    if (readcount == 0) {
        pthread_mutex_unlock(&wrt);
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void *writer(void *arg) {
    int id = *((int *)arg);
    pthread_mutex_lock(&wrt);
    shared_data += 10;
    printf("Writer %d: updated shared_data to %d\n", id, shared_data);
    sleep(2);
    pthread_mutex_unlock(&wrt);
    pthread_exit(NULL);
}

int main() {
    pthread_t r[5], w[2];
    int i;
    int r_id[5] = {1, 2, 3, 4, 5};
    int w_id[2] = {1, 2};

    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&wrt, NULL);

    pthread_create(&r[0], NULL, reader, &r_id[0]);
    pthread_create(&w[0], NULL, writer, &w_id[0]);
    pthread_create(&r[1], NULL, reader, &r_id[1]);
    pthread_create(&r[2], NULL, reader, &r_id[2]);
    pthread_create(&w[1], NULL, writer, &w_id[1]);
    pthread_create(&r[3], NULL, reader, &r_id[3]);
    pthread_create(&r[4], NULL, reader, &r_id[4]);

    for (i = 0; i < 5; i++)
        pthread_join(r[i], NULL);
    for (i = 0; i < 2; i++)
        pthread_join(w[i], NULL);

    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&wrt);
    return 0;
}



