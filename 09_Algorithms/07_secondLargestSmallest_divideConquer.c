# include <stdio.h>
# include <limits.h>

# define MAX 100

int max(int a, int b) {return (a > b ? a : b);}
int min(int a, int b) {return (a < b ? a : b);}

int secLargest(int arr[], int low, int high){
    // For single element array
    if(low == high) return INT_MIN;

    // if only 2 element present in the array
    if(high == low + 1) {return (arr[low] < arr[high] ? arr[low] : arr[high]);}

    int mid = low + (high - low)/2;

    // Left array
    int left = secLargest(arr,low,mid);
    
    // Right array
    int right = secLargest(arr, mid + 1, high);

    // Calculeate largest in the left array
    int leftLargest = arr[low];
    for(int i = low; i <= mid; i ++){
        if(arr[i] > leftLargest) leftLargest = arr[i];
    }

    // Calculate largest in the right array
    int rightLargest = arr[mid+1];
    for(int i = mid + 1; i <= high; i++){
        if(arr[i] > rightLargest) rightLargest = arr[i];
    }

    if(leftLargest > rightLargest) {return max(left, rightLargest);}
    if(leftLargest < rightLargest) {return max(right, leftLargest);}
}

int secSmallest(int arr[], int low, int high){
    // For single element array
    if(low == high) return INT_MAX;

    // if only 2 element present in the array
    if(high == low + 1) {return (arr[low] > arr[high] ? arr[low] : arr[high]);}

    int mid = low + (high - low)/2;

    // Left array
    int left = secSmallest(arr,low,mid);
    
    // Right array
    int right = secSmallest(arr, mid + 1, high);

    // Calculeate smallest in the left array
    int leftSmallest = arr[low];
    for(int i = low; i <= mid; i ++){
        if(arr[i] < leftSmallest) leftSmallest = arr[i];
    }

    // Calculate smallest in the right array
    int rightSmallest = arr[mid+1];
    for(int i = mid + 1; i <= high; i++){
        if(arr[i] < rightSmallest) rightSmallest = arr[i];
    }

    if(leftSmallest < rightSmallest) {return min(left, rightSmallest);}
    else {return min(right, leftSmallest);}
}

int main () {
    int arr[MAX];
    int n;

    printf("Enter the number of element in your array: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for(int i =0; i< n; i++){
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("The 2nd largest element of your array is: %d\n", secLargest(arr, 0, n-1));
    printf("The 2nd smallest element of your array is: %d\n", secSmallest(arr, 0, n-1));

    return 0;
}