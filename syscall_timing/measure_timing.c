#include <stdio.h>
#include <sys/time.h>

int main(void) {
    struct timeval time1, time2;
    gettimeofday(&time1, NULL);
    gettimeofday(&time2, NULL);

    printf("time1: %ld  %ld\n", time1.tv_sec, time1.tv_usec);
    printf("time2: %ld  %ld\n", time2.tv_sec, time2.tv_usec);
    
    return 0;
}

