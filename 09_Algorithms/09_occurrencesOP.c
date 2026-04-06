# include <stdio.h>
# define MAX 100

int firstOccurrence(int arr[], int n, int x){
    int left = 0, right = n - 1, ans = -1;

    while (left <= right){
        int mid = left + (right - left)/2;

        if(arr[mid] == x){
            ans = mid;
            right = mid - 1; // left shift
        }
        else if (arr[mid] < x){
            left = mid + 1;
        }
        else 
            right = mid - 1;
    }
    return ans;
}

int lastOccurrence(int arr[], int n, int x){
    int left = 0, right = n -1, ans = -1;

    while (left <= right) {
        int mid = left + (right - left)/2;

        if (arr[mid] == x){
            ans = mid;
            left = mid + 1;
        }
        else if(arr[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return ans;
}

int countOccurrences(int arr[], int n, int x){
    int first = firstOccurrence(arr, n, x);
    if(first == -1) return 0;

    int last = lastOccurrence(arr, n, x);

    return last - first + 1;
}

int main(){
    int arr[MAX];
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of x: ");
    scanf("%d", &x);

    int result = countOccurrences(arr, n, x);

    printf("The occurrences of %d = %d\n", x, result);

    return 0;
}