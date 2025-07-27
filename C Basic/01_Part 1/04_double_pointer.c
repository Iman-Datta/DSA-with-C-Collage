# include <stdio.h>

int main() {
    int a, b;
    int *ptr1, *ptr2;
    printf("Enter the value of a: ");
    scanf("%d", &a);
    
    printf("Enter the value of b: ");
    scanf("%d", &b);

    ptr1 = &a;
    ptr2 = &b;

    int **pptr = &ptr1;
    printf("The value of a useing pointer: %d \n", *ptr1);
    printf("The value of a useing double pointer: %d \n", **pptr);

    **pptr = 90;
    printf("The modified value of a useing double pointer: %d \n", **pptr);

    return 0;
}