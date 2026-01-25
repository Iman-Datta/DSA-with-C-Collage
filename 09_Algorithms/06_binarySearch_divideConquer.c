# include <stdio.h>

# define MAX 100

int binarySearch(int arr[], int low, int high, int target){
    if (low > high){
        return -1;
    }
    int mid = (low + (high - low)/2);
    if(arr[mid] == target) return mid;
    else if(target < arr[mid]){
        return binarySearch(arr, low, mid - 1, target);
    }
    else
        return binarySearch(arr, mid + 1, high, target);
}

int main() {
    int n, target;
    int arr[MAX];

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the sorted array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to search: ");
    scanf("%d", &target);

    int index = binarySearch(arr, 0, n - 1, target);

    if (index != -1)
        printf("Element %d found at index %d.\n", target, index);
    else
        printf("Element %d not found in the array.\n", target);

    return 0;
}