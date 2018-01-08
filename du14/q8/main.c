#include "mydef.h"

#include <stdlib.h>
#include <time.h>

void initialize (int data[WMAX][HMAX]);
void randPlot (int data[WMAX][HMAX], BLOCK_IMAGE CO);
void printData (int data[WMAX][HMAX]);

int main (){
    int maze[WMAX][HMAX], i;
    initialize(maze);
    srand((unsigned)time(NULL));
    for (i = 0; i != 20; ++i) {
        randPlot(maze, BLACK);
    }
    printData(maze);
    return 0;
}
