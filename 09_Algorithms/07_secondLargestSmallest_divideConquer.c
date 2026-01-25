// Find the second largest and second smallest number simultaneously in an array using Divide & Conquer Principle.

#include <stdio.h>
#include <limits.h>

typedef struct {
    int smallest;
    int secondSmallest;
    int largest;
    int secondLargest;
} Result;

// Divide & Conquer Function
Result findSecondMinMax(int arr[], int low, int high) {
    Result res;

    // Case 1: Only one element
    if (low == high) {
        res.smallest = arr[low];
        res.secondSmallest = INT_MAX;
        res.largest = arr[low];
        res.secondLargest = INT_MIN;
        return res;
    }

    // Case 2: Exactly two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            res.smallest = arr[low];
            res.secondSmallest = arr[high];

            res.largest = arr[high];
            res.secondLargest = arr[low];
        } else {
            res.smallest = arr[high];
            res.secondSmallest = arr[low];

            res.largest = arr[low];
            res.secondLargest = arr[high];
        }
        return res;
    }

    // Divide
    int mid = (low + high) / 2;

    Result left = findSecondMinMax(arr, low, mid);
    Result right = findSecondMinMax(arr, mid + 1, high);

    Result ans;

    // Combine — Smallest & Second Smallest
    if (left.smallest < right.smallest) {
        ans.smallest = left.smallest;
        ans.secondSmallest =
            (left.secondSmallest < right.smallest)
                ? left.secondSmallest
                : right.smallest;
    } else {
        ans.smallest = right.smallest;
        ans.secondSmallest =
            (right.secondSmallest < left.smallest)
                ? right.secondSmallest
                : left.smallest;
    }

    // Combine — Largest & Second Largest
    if (left.largest > right.largest) {
        ans.largest = left.largest;
        ans.secondLargest =
            (left.secondLargest > right.largest)
                ? left.secondLargest
                : right.largest;
    } else {
        ans.largest = right.largest;
        ans.secondLargest =
            (right.secondLargest > left.largest)
                ? right.secondLargest
                : left.largest;
    }

    return ans;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Result r = findSecondMinMax(arr, 0, n - 1);

    printf("\nSecond Smallest: %d\n", r.secondSmallest);
    printf("Second Largest: %d\n", r.secondLargest);

    return 0;
}
