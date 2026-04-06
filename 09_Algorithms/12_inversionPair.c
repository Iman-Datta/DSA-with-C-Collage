#include <stdio.h>

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;      // left subarray
    int j = mid + 1;   // right subarray
    int k = left;      // temp array index
    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            
            // Count inversions
            inv_count += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid, right);
    }

    return inv_count;
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];

    long long inversions = mergeSort(arr, temp, 0, n - 1);

    printf("Number of inversion pairs = %lld\n", inversions);

    return 0;
}