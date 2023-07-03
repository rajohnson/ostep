#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int x = 1;
    int pid = fork();

    if (pid == 0)
    {
        execlp("/bin/ls", "ls", "-l", NULL);
        return 0;
    }
    else
    {
        wait(NULL);
        printf("goodbye\n");
    }

    return 0;
}