#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int x = 1;
    int pid = fork();

    if (pid == 0)
    {
        printf("child\n");
        int result = wait(NULL);
        printf("result: %d\n", result);

        return 0;
    }
    else
    {
        wait(NULL);
        printf("parent\n");
    }

    return 0;
}