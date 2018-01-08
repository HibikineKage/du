#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int * data;
    printf("何個データを入れますか？:");
    scanf("%d", &n);

    data = malloc(sizeof(int) * n);
    if (data == NULL) {
        fprintf(stderr, "メモリ不足\n");
        return 1;
    }
    printf("OK\n");
    for(i = 0; i != n; ++i) {
        printf("%d:", i);
        scanf("%d", &data[i]);
    }
    for(i = 0; i < n; ++i) {
        printf("%d\n", data[i]);
    }
    return 0;
}
