# include <stdio.h>
# include <stdlib.h>

typedef struct Student {
    char name[50];
    int age;
} student;

int main () {
    student *s;
    char temp[100];

    s = (student*)malloc(sizeof(student));

    printf("Enter your name: ");
    fgets(s->name, sizeof(s->name), stdin);

    // getchar();

    printf("Enter your age: ");
    scanf("%d", &s->age);

    printf("Your name: %s", s->name);
    printf("Your age: %d", s->age);

    return 0;
}