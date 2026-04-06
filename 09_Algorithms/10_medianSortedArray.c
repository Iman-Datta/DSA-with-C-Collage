#include <stdio.h>

double midian (int arr[], int n){
    if(n % 2 == 0){
        return (arr[n/2] + arr[n/2 -1])/2.0;
    }
    else 
        return arr[n/2];
}

double findMedianSortedArrays(int a[], int b[], int n){
    if(n == 0) return -1;

    if(n == 1) {return (a[0] + b[0])/2.0;}

    if(n == 2){
        int maxLeft = a[0] > b[0] ? a[0] : b[0];
        int minRight = a[1] < b[1] ? a[1] : b[1];
        return (maxLeft + minRight) / 2.0;
    }

    double m1 = midian(a, n);
    double m2 = midian(b, n);

    if(m1 < m2){
        if(n%2 == 0){
            return findMedianSortedArrays(a + n/2 - 1, b, n - n/2 + 1);
        }
        else
            return findMedianSortedArrays(a + n/2, b, n - n/2);
    }
    else
        if(n%2 == 0){
            return findMedianSortedArrays(a, b + n/2 - 1, n - n/2 + 1);
        }
        else
            return findMedianSortedArrays(a, b + n/2, n - n/2);
}

int main() {
    int A[] = {1, 3, 5, 7};
    int B[] = {2, 4, 6, 8};

    int n = sizeof(A) / sizeof(A[0]);

    printf("Median = %.2f\n", findMedianSortedArrays(A, B, n));

    return 0;
}