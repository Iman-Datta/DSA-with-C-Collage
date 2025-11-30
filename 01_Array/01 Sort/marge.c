#include <stdio.h>

// This function merges two sorted parts of the array
// left part:  a[l .. m]
// right part: a[m+1 .. r]
void merge(int a[], int l, int m, int r) {

    int i = l;      // pointer for left sub-array
    int j = m + 1;  // pointer for right sub-array
    int k = l;      // pointer for temporary array
 
    int temp[10];   // temporary array to store sorted values

    // Compare elements from both sub-arrays
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) {
            temp[k] = a[i];  // copy smaller element
            i++;
        } else {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left sub-array (if any)
    while (i <= m) {
        temp[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements of right sub-array (if any)
    while (j <= r) {
        temp[k] = a[j];
        j++;
        k++;
    }

    // Copy sorted elements back into original array
    for (i = l; i <= r; i++) {
        a[i] = temp[i];
    }
}

// Recursive Merge Sort function
void mergeSort(int a[], int l, int r) {

    // Base condition: at least two elements
    if (l < r) {

        // Find the middle index
        int m = (l + r) / 2;

        // Recursively sort left half
        mergeSort(a, l, m);

        // Recursively sort right half
        mergeSort(a, m + 1, r);

        // Merge the sorted halves
        merge(a, l, m, r);
    }
}

int main() {
    int a[5] = {4, 1, 5, 2, 3};
    int i;

    // Apply merge sort on full array
    mergeSort(a, 0, 4);

    // Print sorted array
    printf("Sorted array: ");
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);

    return 0;
}
