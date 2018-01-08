#include "mydef.h"
#include <stdlib.h>
#include <time.h>

void randPlot(int data[WMAX][HMAX], BLOCK_IMAGE CO) {
    int x, y;
    x = rand() % (WMAX - 1) + 1;
    y = rand() % (HMAX - 1) + 1;
    data[x][y] = CO;
    return;
}
