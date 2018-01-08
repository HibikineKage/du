#include "mydef.h"


int printALL(struct Dtype data[], int Dnum) {
    int loop, snum;
    for (loop = 0; loop != Dnum; ++loop) {
        printf("----[%2d]-----\n", loop + 1);
        printf("Name: %s\n", data[loop].name);
        printf("Address: %s\n", data[loop].address);
        for (snum = 0; snum< SCORENUM; ++snum) {
            printf("score[%d]: %3d\t", snum + 1, data[loop].score[snum]);
        }
        printf("\n");
    }
}
