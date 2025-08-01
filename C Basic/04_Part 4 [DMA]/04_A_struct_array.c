# include <stdio.h>
# include <stdlib.h>

# define SIZE 100

typedef struct Student {
    char name[50];
    int age;
} student;

// int main () {
//     student *s[SIZE];
//     int n;

//     printf("How many student you want to add: ");
//     scanf("%d", &n);
//     getchar(); // consume newline left by scanf
//     for (int i = 0; i < n; i++){
//         s[i] = (student*)malloc(sizeof(student));
//         printf("Enter your name: ");
//         fgets(s[i]->name, sizeof(s[i]->name), stdin);

//         printf("Enter your age: ");
//         scanf("%d", &s[i]->age);
//         getchar(); // consume newline left by scanf
//     }

//     for (int i = 0; i < n; i++) {
//         printf("Your name: %s", s[i]->name);
//         printf("Your age: %d\n", s[i]->age);
//     }

//     return 0;
// }

int main () {
    student *s[SIZE];
    int n;

    printf("Enter nuber of student: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++){
        s[i] = (student*)malloc(sizeof(student));

        printf("Details of %d student ==> \n", i+1);
        printf("Enter your name: ");
        fgets(s[i]->name, sizeof(s[i]->name), stdin);
        printf("Enter your age: ");
        scanf("%d", &s[i]->age);
        getchar();
    }

    for(int i = 0; i < n; i ++){
        printf("%d Student ==> \n", i+1);
        printf("Student name: %s", s[i]->name);
        printf("Student age: %d", s[i]->age);
    }
    return 0;
}