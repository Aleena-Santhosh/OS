#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("PCCSL407 ");
    } 
    else if (pid > 0) {
        printf("Operating System Labs");
        wait(NULL);
    } 
    else {
        printf("fork failed");
        return 1;
    }

    return 0;
}
