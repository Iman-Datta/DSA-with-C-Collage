# include <stdio.h>
#include<stdlib.h>
#include<string.h>
# define SIZE 100

typedef struct Date{
    int day;
    int month;
    int year;
}date;

typedef struct emp
{
    int id;
    float salary;
    char* name;
    date* doj;
}emp;

int main(){
    int n;

    // emp* p = (emp*)malloc(sizeof(emp));
    // p->name = (char*)malloc(20*sizeof(char));
    // strcpy(p->name, "imon");
    // p->doj = (date*)malloc(20*sizeof(date));

    printf("Enter the number of employee: ");
    scanf("%d", &n);
    getchar();
    emp* arr = (emp*)malloc(n * sizeof(emp));

    for(int i = 0; i < n; i++) {
        arr[i].name = (char*)malloc(100 * sizeof(char));
        arr[i].doj = (date*)malloc(sizeof(date));
        printf("Enter the details of %d employee \n", i+1);
        // getchar();
        printf("Enter the name: ");
        fgets(arr[i].name, SIZE, stdin);
        // getchar();
        arr->id = i++;
        printf("Enter the salary: ");
        scanf("%f", &arr[i].salary);
        getchar();
        printf("Enter date of joining (dd mm yyyy): ");
        scanf("%d %d %d", &arr[i].doj->day, &arr[i].doj->month, &arr[i].doj->year);
        // getchar();
    }

    printf("\nEmployee Details\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d\n", arr[i].id);
        printf("Name: %s\n", arr[i].name);
        printf("Date of Joining: %02d/%02d/%d\n", arr[i].doj->day, arr[i].doj->month, arr[i].doj->year);
        printf("****************************\n");
    }
    // getchar();
    return 0;
}