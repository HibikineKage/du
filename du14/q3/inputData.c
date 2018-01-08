#include "mydef.h"

int inputData(DTYPE data[], int* Dnum) {
    int loop, addnum, snum;
    printf("何個データを追加しますか?[あと%d個まで可能]", DATANUM - *Dnum);
    scanf("%d", &addnum);
    for(loop = *Dnum; loop< *Dnum + addnum; ++loop) {
        printf("Name:");
        scanf("%s", data[loop].name);
        printf("Address:");
        scanf("%s", data[loop].address);
        for(snum = 0; snum < SCORENUM; snum++) {
            printf("score[%d]:", snum + 1);
            scanf("%d", &data[loop].score[snum]);
        }
    }
    *Dnum += addnum;
    return 0;
}


