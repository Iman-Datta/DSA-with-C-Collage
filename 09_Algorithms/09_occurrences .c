# include <stdio.h>
# define MAX 100

int occurrences(int arr[], int n, int x){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == x){
            count ++;
        }
    }
    return count;
}

int main() {
    int arr[MAX];
    int n,x;

    printf("Enter the number of element in your array: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for(int i =0; i< n; i++){
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of X: ");
    scanf("%d", &x);

    int result = printf("The occurrences of %d is: %d", x, occurrences(arr,n,x));
    return 0;
}