#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
    // Cleanup functions will be skipped
    atexit(cleanup_1);
    atexit(cleanup_2);

    // Can also use _exit() from <unistd.h>
    // _Exit(EXIT_SUCCESS);
    _Exit(EXIT_FAILURE);
    return 0;
}
