#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool twoSumHash(int arr[], int n, int target) {
    int hash[MAX] = {0};   // simple hash array

    for (int i = 0; i < n; i++) {
        int needed = target - arr[i];

        // check if needed already exists
        if (needed >= 0 && needed < MAX && hash[needed] == 1) {
            printf("Pair found: %d and %d\n", arr[i], needed);
            return true;
        }

        // store current element
        hash[arr[i]] = 1;
    }

    return false;
}

int main() {
    int arr[] = {7, 2, 11, 15};
    int n = 4;
    int target = 9;

    if (!twoSumHash(arr, n, target)) {
        printf("No pair found.\n");
    }
    else{
        printf("pair found");
    }

    return 0;
}