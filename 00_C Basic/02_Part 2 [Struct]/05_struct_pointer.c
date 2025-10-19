#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    float marks;
};

int main() {
    struct Student s1;
    struct Student *ptr;

    ptr = (struct Student*)malloc(sizeof(struct Student));

    s1.roll = 10;
    s1.marks = 88.5;

    ptr->roll = 20;
    ptr->marks = 92.3;

    printf("s1: %d %.2f\n", s1.roll, s1.marks);
    printf("ptr: %d %.2f\n", ptr->roll, ptr->marks);

    return 0;
}
