#include <stdio.h>
#include <unistd.h>
#include <sys/prctl.h>

int main() {

    prctl(PR_SET_NAME, "ParentProcess");

    pid_t pid = fork();

    if (pid == 0) {
        prctl(PR_SET_NAME, "ChildProcess");
        sleep(10);
    } else {
        sleep(10);
    }
    sleep(100)
    return 0;
}