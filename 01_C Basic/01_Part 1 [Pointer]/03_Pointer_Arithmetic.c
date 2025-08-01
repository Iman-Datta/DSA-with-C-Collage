# include <stdio.h>
# define SIZE 100

int main () {
    int i, arr[SIZE], n, *arrPtr;
    printf("Enter the size of teh array: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i ++) {
        printf("Enter the value of %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    arrPtr = &arr[SIZE];
    printf("%d \n", arr);
    printf("%d \n", *arr);
    
    int *t = arr;
    for(i = 0; i < n; i++) {
        printf("The %d element is: %d \n", i+1, *(t+i));
    }
    return 0;
}