#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void randGen() {
    int i = 0;
    srand((unsigned)time(NULL));
    for(; i != 15; ++i) {
        printf("%d\n", rand() % 10 + 1);
    }
}

int main() {
    randGen();
    return 0;
}
