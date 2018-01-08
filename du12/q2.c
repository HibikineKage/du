#include <stdio.h>
#include <string.h>

struct Address_data {
    char name[81];
    char phone[20];
    unsigned int old;
};

int show(struct Address_data data) {
    return printf("%s\t(%d)\t[%s]\n", data.name, data.old, data.phone);
}

int main() {
    struct Address_data data1, data2;
    
    strcpy(data1.name, "Alex");
    data1.old = 20;
    strcpy(data1.phone, "046-000-0001");
    
    strcpy(data2.name, "Bonnie");
    data2.old = 15;
    strcpy(data2.phone, "046-000-0002");
    
    show(data1);
    show(data2);
    return 0;
}