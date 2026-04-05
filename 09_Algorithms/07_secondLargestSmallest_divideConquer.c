#include <stdio.h>
#include <limits.h>

#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int secLargest(int arr[], int low, int high) {
    if (low == high)
        return INT_MIN;

    if (high == low + 1)
        return (arr[low] < arr[high]) ? arr[low] : arr[high];

    int mid = low + (high - low) / 2;

    int left = secLargest(arr, low, mid);
    int right = secLargest(arr, mid + 1, high);

    int largestLeft = arr[low];
    for (int i = low; i <= mid; i++)
        if (arr[i] > largestLeft)
            largestLeft = arr[i];

    int largestRight = arr[mid + 1];
    for (int i = mid + 1; i <= high; i++)
        if (arr[i] > largestRight)
            largestRight = arr[i];

    if (largestLeft > largestRight)
        return max(left, largestRight);
    else
        return max(right, largestLeft);
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int secSmallest(int arr[], int low, int high) {
    if (low == high)
        return INT_MAX;

    if (high == low + 1)
        return (arr[low] > arr[high]) ? arr[low] : arr[high];

    int mid = low + (high - low) / 2;

    int left = secSmallest(arr, low, mid);
    int right = secSmallest(arr, mid + 1, high);

    int smallestLeft = arr[low];
    for (int i = low; i <= mid; i++)
        if (arr[i] < smallestLeft)
            smallestLeft = arr[i];

    int smallestRight = arr[mid + 1];
    for (int i = mid + 1; i <= high; i++)
        if (arr[i] < smallestRight)
            smallestRight = arr[i];

    if (smallestLeft < smallestRight)
        return min(left, smallestRight);
    else
        return min(right, smallestLeft);
}

int main(){
    int arr[MAX];
    int n;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the sorted array elements:\n");
    for(int i =0; i< n; i++){
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Second Largest = %d\n", secLargest(arr, 0, n - 1));
    printf("Second Smallest = %d\n", secSmallest(arr, 0, n - 1));

    return 0;
}