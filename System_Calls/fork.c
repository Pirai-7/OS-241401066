#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    } 
    else if (pid == 0) {
        printf("Child Process: My PID = %d, My Parent's PID = %d\n", getpid(), getppid());
    } 
    else {
        wait(NULL);
        printf("Parent Process: My PID = %d, My Child's PID = %d\n", getpid(), pid);
        printf("Child process finished execution. Parent exiting.\n");
    }

    return 0;
}
