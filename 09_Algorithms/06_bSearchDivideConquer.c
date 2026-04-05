# include <stdio.h>
# include <stdbool.h>

# define MAX 100

bool binarySearch(int arr[], int left, int right, int target){
    while (left <= right){
        int mid = left + (right - left)/2;

        if(arr[mid] == target) return true;
        else if(arr[mid] < target) return binarySearch(arr, mid + 1, right, target);
        else return binarySearch(arr, left, mid - 1, target);
    }
    return false;
}

int main(){
    int arr[MAX];
    int n, target;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the sorted array elements:\n");
    for(int i =0; i< n; i++){
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to search: ");
    scanf("%d", &target);

    bool result = binarySearch(arr,0,n-1,target);
    if(result) printf("target found");
    else printf("Target not found");

    return 0;
}