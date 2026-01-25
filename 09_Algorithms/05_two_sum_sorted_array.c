// Given a sorted array and a number X, search two elements of the array such that their sum is X. Expected time complexity is O(n).

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int leftIndex;
    int rightIndex;
} Pair;         

bool hasTwoSum(int arr[], int n, int target){
    int low = 0, high = n -1;
    while (low < high) {
        int currentSum  = arr[low] + arr[high];
        if (currentSum  == target) return true;
        else if (currentSum  < target) low ++;
        else high --;
    }
    return false;
}

Pair findTwoSumPair(int arr[], int n, int target){
    Pair result;
    result.leftIndex = -1;
    result.rightIndex = -1;
    int low = 0, high = n -1;
    while (low < high) {
        int currentSum  = arr[low] + arr[high];
        if (currentSum  == target) {
            result.leftIndex = low;
            result.rightIndex = high;
            return result;
        }
        else if (currentSum  < target) low ++;
        else high --;
    }
    return result;
}

int main() {
    int n, target;
    int arr[MAX];

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of X: ");
    scanf("%d", &target);

    if (hasTwoSum(arr, n, target)) {
        printf("Yes, a pair with the sum %d exists in the array.\n", target);

        Pair p = findTwoSumPair(arr, n, target);

        if (p.leftIndex != -1 && p.rightIndex != -1) {
            printf("The pair is found at indices: %d and %d\n", p.leftIndex, p.rightIndex);
            printf("Values are: %d + %d = %d\n", arr[p.leftIndex], arr[p.rightIndex], target);
        }
        else {
            printf("But could not fetch the pair (logic missing or pair not valid).\n");
        }

    } else {
        printf("No, there is no pair that adds up to %d.\n", target);
    }

    return 0;
}
