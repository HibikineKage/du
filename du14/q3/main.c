#include "mydef.h"

int printALL(DTYPE data[], int Dnum);
int inputData(DTYPE data[], int *Dnum);

int main() {
    DTYPE data[DATANUM];
    int Dnum = 0;
    inputData(data, &Dnum);
    printALL(data, Dnum);
    printf("\n==Now Dnum=%d\n\n", Dnum);
    inputData(data, &Dnum);
    printALL(data, Dnum);
    return 0;
}
