#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int x = 1;
    int pid = fork();

    if (pid == 0)
    {
        printf("hello\n");
        return 0;
    }
    else
    {
        for (volatile int i = 0; i < 1000000; i++)
        {
        }
        printf("goodbye\n");
    }

    return 0;
}