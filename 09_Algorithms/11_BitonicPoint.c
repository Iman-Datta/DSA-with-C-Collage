#include <stdio.h>

int findBitonicPoint(int arr[], int n) {
    int count = 0;
    int indx = -1;
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            indx = i;
            count ++;
        }
    }
    if(count > 1){
        indx = -1;
    }
    return indx;
}

int main() {
    int arr[] = {1, 3, 8, 12, 9, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int index = findBitonicPoint(arr, n);
    
    printf("Bitonic element = %d", arr[index]);

    return 0;
}