# include <stdio.h>
# include <stdlib.h>

int main () {
    int *arr, size, i;

    arr = (int*)malloc(sizeof(int));

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    for (i= 0; i < size; i++) {
        printf("Enter %d element: ", i+1);
        scanf("%d", &arr[i]);
    }
    for (i= 0; i < size; i++) {
        printf("%d element is: %d \n", i+1, arr[i]);
    }

    return 0;
}