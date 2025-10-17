# include <stdio.h>
# define SIZE 100
struct employee {
    char name[SIZE];
    int id;
    float salary;
};

int main() {
    struct employee emp1;

    emp1.id = 0;
    printf("Enter your name: ");
    gets(emp1.name);  // gets is deprecrated

    printf("Enter your salary: ");
    scanf("%f", &emp1.salary);

    emp1.id ++;

    printf("Name: %s \n", emp1.name);
    printf("id: %d \n", emp1.id);
    printf("Salary: %f \n", emp1.salary);

    return 0;
}