#include <stdio.h>

#define DNUM 3

typedef struct Human_data {
    char name[81];
    char id[10];
} Human_data_type;

void inMod (Human_data_type * const data, const int size) {
    int i = 0;
    for(; i != size; ++i) {
        printf("%3d: Name:", i + 1);
        scanf("%80s", data[i].name);
        printf("%3d: ID:", i + 1);
        scanf("%9s", data[i].id);
    }
}

void outMod(const Human_data_type * const data, const int size) {
    int i = 0;
    for(; i != size; ++i) {
        printf("%s\t", data[i].name);
        printf("[%s]\n", data[i].id);
    }
}

int main (){
    Human_data_type data[DNUM];
    inMod(data, DNUM);
    outMod(data, DNUM);
    return 0;
}
