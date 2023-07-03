#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int x = 1;
    int pid = fork();

    if (pid == 0)
    {
        execle("/bin/ls", "ls", "-l", NULL, NULL);
        return 0;
    }
    else
    {
        wait(NULL);
        printf("goodbye\n");
    }

    return 0;
}