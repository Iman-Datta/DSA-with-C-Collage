# include <stdio.h>
#include <limits.h>

# define MAX 100

int secLargest(int arr[], int n){
    int largest = arr[0];
    int secLargest = INT_MIN;

    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            secLargest = largest;
            largest = arr[i];
        }

        else if(arr[i] < largest && arr[i] > secLargest){
            secLargest = arr[i];
        }
    }
    return secLargest;
}

int secSmallest(int arr[], int n){
    int smallest = arr[0];
    int secSmallest = INT_MAX;

    for(int i =0; i < n; i++){
        if(arr[i] < smallest){
            secSmallest = smallest;
            smallest = arr[i];
        }

        else if(arr[i] > smallest && arr[i]<secSmallest){
            secSmallest = arr[i];
        }
    }
    return secSmallest;
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

    printf("The 2nd largest element of your array is: %d\n", secLargest(arr,n));
    printf("The 2nd smallest element of your array is: %d\n", secSmallest(arr,n));

    return 0;
}