#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int x = 1;
    int pid = fork();

    for (int i = 0; i < 100; i++)
    {
        printf("x: %d, pid: %d\n", x++, pid);
    }

    return 0;
}