#include <stdio.h>
#include <string.h>

struct Address_data {
    char name[81];
    char phone[20];
    unsigned int old;
};

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
    show(inputData());
    return 0;
}