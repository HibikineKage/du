#include "mydef.h"

void initialize (int data[WMAX][HMAX]) {
    int x, y;

    for (y = 0; y != HMAX; ++y) {
        for (x = 0; x != WMAX; ++x) {
            if(x == 0 || x == WMAX - 1 || y == 0 || y == HMAX - 1) {
                data[x][y] = BLACK;
            } else {
                data[x][y] = WHITE;
            }
        }
    }
    data[STX][STY] = START;
    data[GLX][GLY] = GOAL;
    return;
}
