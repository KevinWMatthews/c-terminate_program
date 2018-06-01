#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void child_process(void)
{
    pid_t pid = getpid();
    printf("Entering the child process: %d\n", pid);

    // Must exit! If you do not exit, the child process will return and continue executing.
    printf("Exiting child process\n");

    // Calling exit() is not recommended.
    // It executes all cleanup functions registered in userspace, flushes buffers, and releases temp files
    // exit(EXIT_SUCCESS);

    // Instead, use _exit() [unistd.h] or _Exit() [stdlib.h]
    // These will execute the child process without calling cleanup functions
    _Exit(EXIT_SUCCESS);
}

void parent_process(pid_t pid)
{
    printf("Parent spawned process: %d\n", pid);
}

void cleanup_1(void)
{
    printf("In %s\n", __func__);
}

void cleanup_2(void)
{
    printf("In %s\n", __func__);
}

int main(void)
{
    pid_t pid;

    atexit(cleanup_1);
    atexit(cleanup_2);

    pid = fork();
    if (pid == 0)
    {
        child_process();
        fprintf(stderr, "Child process should not return!\n");
    }
    else if (pid < 0)
    {
        fprintf(stderr, "Failed to fork!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        parent_process(pid);
        printf("Parent process moving on.\n");
    }

    while (1)
    {
        ;       // hang so we can inspect the processes
    }

    return 0;
}
