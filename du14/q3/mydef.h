#include <stdio.h>

#define CLEN 81
#define SCORENUM 3
#define DATANUM 10

typedef struct Dtype {
    char name[CLEN];
    char address[CLEN];
    int score[SCORENUM];
} DTYPE;
