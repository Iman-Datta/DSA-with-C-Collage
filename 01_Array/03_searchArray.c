#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *arr, int sz, int target) {
    for (int i = 0; i < sz; i++) {
        if (*(arr + i) == target) { // arr[i] == target
            return i;
        }
    }
    return -1;
}

int binarySearch(int *arr, int sz, int target) { // Binary Search only applid on sorted array. worst time complexity = log(n)
    int low = 0, high = sz - 1, mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (*(arr + mid) == target) {
            return mid;
        }
        else if (*(arr + mid) < target){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return -1;
}

void displayResult(int result) {
    if (result == -1)
        printf("Element not found.\n");
    else
        printf("Element found at index %d\n", result);
}

int menu() {
    int choice;
    printf("\n====== MENU ======\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int target, choice;
    int arr[] = {10, 19, 21, 22, 33, 33, 65};  // sorted for binary search
    int sz = sizeof(arr) / sizeof(arr[0]);
    printf("Enter the element to search: ");
    scanf("%d", &target);

    do {
        choice = menu();
        int result;

        switch (choice) {
            case 1:
                printf("You selected: Linear Search\n");
                result = linearSearch(arr, sz, target);
                displayResult(result);
                break;

            case 2:
                printf("You selected: Binary Search\n");
                result = binarySearch(arr, sz, target);
                displayResult(result);
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 3);

    return 0;
}