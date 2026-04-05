// Given a sorted array and a number X, search two elements of the array such that their sum is X. Expected time complexity is O(n).

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool findTwoSumPair(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while(left < right){
        int sum = arr[left] + arr[right];

        if(sum == target) return true;
        else if (sum < target) left ++;
        else right --;
    }

    return false;
}

int main() {
    int n, target;
    int arr[MAX];

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the sorted elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of X: ");
    scanf("%d", &target);

    bool result = findTwoSumPair(arr, n, target);
    
    if (result)
    printf("Pair found.\n");

    if (!result)
        printf("No pair found.\n");

    return 0;
}