#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int x = 1;
    FILE *fp = fopen("fork_output.txt", "w");
    int pid = fork();

    if (pid < 0)
    {
        fprintf(fp, "Fork failed\n");
        return 1;
    }

    for (int i = 0; i < 10000; i++)
    {
        printf("x: %d, pid: %d\n", x++, pid);

        if (pid == 0)
        {
            // Child process
            fprintf(fp, "Child process\n");
        }
        else
        {
            // Parent process
            fprintf(fp, "Parent process\n");
        }
    }

    if (pid != 0)
    {
        wait(NULL);
        fclose(fp);
    }

    return 0;
}