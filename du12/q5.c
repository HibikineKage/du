#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 10

struct Address_data {
    char name[81];
    char phone[20];
    unsigned int old;
};

int swap(struct Address_data * data1, struct Address_data * data2) {
    struct Address_data * tmp = data1;
    data1 = data2;
    data2 = tmp;
    return 0;
}

int compare_Address_data(const void * a, const void * b) {
    return ((struct Address_data *)a)->old - ((struct Address_data *)b)->old;
}

struct Address_data inputData() {
    struct Address_data data;
    printf("Input a name\n>>");
    scanf("%s", data.name);
    printf("Input a phone number\n>>");
    scanf("%s", data.phone);
    printf("Input a years old\n>>");
    scanf("%u", &data.old);
    return data;
}

int show(struct Address_data data) {
    return printf("%s\t(%u)\t[%s]\n", data.name, data.old, data.phone);
}

int main() {
    struct Address_data data[LEN];
    int i = 0;
    for(; i != LEN; ++i) {
        printf("%d:\n", i+1);
        data[i] = inputData();
    }
    qsort(data, LEN, sizeof(struct Address_data), compare_Address_data);
    for(i = 0; i != LEN; ++i) {
        show(data[i]);
    }
    return 0;
}