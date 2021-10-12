#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 10000

int saldo;
pthread_mutex_t saldoLock = PTHREAD_MUTEX_INITIALIZER;

void* suma100(void *arg){
    int localSaldo = saldo;
    pthread_mutex_lock(&saldoLock);
    localSaldo += 100;
    saldo = localSaldo;
    pthread_mutex_unlock(&saldoLock);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    saldo = 0;
    for (int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, suma100, NULL);
        pthread_join(threads[i], NULL);
    }
    printf("Saldo final = %d\n", saldo);

    pthread_exit(NULL);
}