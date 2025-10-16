#include <stdio.h>
#include <stdlib.h>

int findMax(int *arr, int n) {
    int max = *arr;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) > max)
            max = *(arr + i);
    }
    return max;
}

int findMin(int *arr, int n) {
    int min = *arr;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) < min)
            min = *(arr + i);
    }
    return min;
}

int menu() {
    int choice;
    printf("\n====== MENU ======\n");
    printf("1. Find Maximum\n");
    printf("2. Find Minimum\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int *arr, n, choice;

    printf("Enter number of items: ");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    do {
        choice = menu();
        switch (choice) {
            case 1:
                printf("Maximum value: %d\n", findMax(arr, n));
                break;
            case 2:
                printf("Minimum value: %d\n", findMin(arr, n));
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 3);

    free(arr);
    return 0;
}
