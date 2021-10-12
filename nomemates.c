#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handleTerm(int signal){
    printf("Recibi signal %d\n", signal);
}

int main(){
    signal(2, handleTerm);
    while (1){
        printf("Trabajando...\n");
        sleep(1);
    }

    return 0;
}