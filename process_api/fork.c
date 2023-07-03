#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)

{
    int example_pipe[2];
    pipe(example_pipe);

    int pid = fork();

    if (pid == 0)
    {
        printf("child 1\n");

        dup2(example_pipe[1], STDOUT_FILENO);

        printf("child 1 into pipe\n");

        return 0;
    }

    pid = fork();

    if (pid == 0)
    {
        printf("child 2\n");

        dup2(example_pipe[0], STDIN_FILENO);

        char buffer[100] = {0};
        int readlen = read(STDIN_FILENO, buffer, 100);
        printf("child 2 read %d bytes from pipe: %s\n", readlen, buffer);

        return 0;
    }
    else
    {
        waitpid(pid, NULL, 0);
        printf("parent\n");
    }

    return 0;
}