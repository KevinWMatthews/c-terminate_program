#include <stdlib.h>
#include <stdio.h>

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
    // Cleanup functions are executed in reverse registration order, on success only
    atexit(cleanup_1);
    atexit(cleanup_2);

    exit(EXIT_SUCCESS);
    // exit(EXIT_FAILURE);
    return 0;
}
