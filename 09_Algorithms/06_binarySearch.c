# include <stdio.h>
# include <stdbool.h>

# define MAX 100

bool binarySearch(int arr[], int n, int target){
    int right = n -1, left = 0;

    while (left <= right){
        int mid = left + (right - left)/2;

        if(arr[mid] == target){
            return true;
        }
        else if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

int main(){
    int arr[MAX];
    int n, target;

    printf("Enter the number of element in your array: ");
    scanf("%d", &n);

    printf("Enter the sorted array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of X: ");
    scanf("%d", &target);

    bool result = binarySearch(arr,n,target);
    if(result) printf("target found");
    else printf("Target not found");
    return 0;
};