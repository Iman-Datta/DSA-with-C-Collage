#include <stdio.h>
#include <string.h>

#define SIZE 5

typedef struct {
    char name[100];
    float marks;
} Subject;

typedef struct {
    char name[100];
    int roll;
    Subject subjects[SIZE];
    float total;
    float average;
} Student;

int main() {
    Student s1;
    int i, max_index, min_index;
    float max, min;

    printf("Enter student name: ");
    fgets(s1.name, sizeof(s1.name), stdin);
    s1.name[strcspn(s1.name, "\n")] = '\0';

    printf("Enter roll number: ");
    scanf("%d", &s1.roll);
    getchar();

    s1.total = 0;

    printf("\n-------------------- Enter subject names and marks -------------------\n");
    for (i = 0; i < SIZE; i++) {
        printf("Subject %d name: ", i + 1);
        fgets(s1.subjects[i].name, sizeof(s1.subjects[i].name), stdin);

        printf("Marks for %s: ", s1.subjects[i].name);
        scanf("%f", &s1.subjects[i].marks);
        getchar();

        s1.total += s1.subjects[i].marks;
    }

    s1.average = s1.total / SIZE;

    printf("\n--------------------------- Student Report ------------------------\n");
    printf("Name: %s\n", s1.name);
    printf("Roll: %d\n", s1.roll);

    printf("\nSubjects and Marks:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%s: %.2f\n", s1.subjects[i].name, s1.subjects[i].marks);
    }

    max = s1.subjects[0].marks;
    min = s1.subjects[0].marks;

    for (int i = 0; i < SIZE; i++) {
        if (s1.subjects[i].marks > max) {
            max = s1.subjects[i].marks;
            max_index = i;
        }
        if (s1.subjects[i].marks < min) {
            min = s1.subjects[i].marks;
            min_index = i;
        }
    }
    printf("Total Marks: %.2f\n", s1.total);
    printf("Average Marks: %.2f\n", s1.average);
    printf("Highest Marks: %.2f, in subject: %s\n", max, s1.subjects[max_index].name);
    printf("Lowest Marks: %.2f, in subject: %s\n", min, s1.subjects[min_index].name);
    
    return 0;
}