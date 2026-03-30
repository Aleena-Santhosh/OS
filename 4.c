#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process: PID = %d\n", getpid());
    } else if (pid > 0) {
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
        wait(NULL);  
    } else {
        printf("fork");
        return 1;
    }
    return 0;
}
