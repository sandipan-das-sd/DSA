#include <stdio.h>

#define PRINTT(i, limit) \
    do { \
        if (i++ < limit) { \
            printf("I love xplorica\n"); \
            continue; \
        } \
    } while (0)

int main() {
    int i = 0;
    PRINTT(i, 3);
    return 0;
}

