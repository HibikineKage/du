#include <stdio.h>

#define CLEN 81
#define WMAX 20
#define HMAX 20
#define STX 0
#define STY 1
#define GLX (WMAX-1)
#define GLY (HMAX-2)

typedef enum BLOCKS {
    WHITE,
    BLACK,
    START,
    GOAL,
} BLOCK_IMAGE;
