# include <stdio.h>
# define SIZE 100

struct employee {
    char name[50];
    int id;
    float salary;
};

int main () {
    struct employee emp[SIZE];
    int n,i=0;
    printf("Enter the number of employee: ");
    scanf("%d", &n);

    for(i; i<n; i++){
        printf("Enter the details of %d employee \n", i+1);
        getchar();
        printf("Enter the name: ");
        gets(emp[i].name);
        emp[i].id = i+1;
        printf("Enter the salary: ");
        scanf("%f", &emp[i].salary);
        printf("**************************** \n");
    }

    for (i = 0; i < n; i++){
        printf("Details of %d employee: \n", i+1);
        printf("ID: %d \n", emp[i].id);
        printf("Name: %s \n", emp[i].name);
        printf("Salary: %f \n", emp[i].salary);
        printf("**************************** \n");
        printf("");
    }
    return 0;
}