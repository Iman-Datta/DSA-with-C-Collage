// Merge 2 sorted array without using extra space

#include <stdio.h>
#include <math.h>

void mergeSortedArray(int a[],int b[],int m, int n){
    int indx = m + n -1;
    int i = m -1 , j = n -1, tempIndx = indx;

    while (i >= 0 && j >= 0){
        if(a[i] >= b[j]){
            a[indx] = a[i];
            indx --;
            i --;
        }
        else{
            a[indx] = b[j];
            indx --;
            j --;
        }
    }

    while (j >= 0) {
        a[indx--] = b[j--];
    }

    for(int x = 0; x <= tempIndx; x ++){
        printf("%d \t", a[x]);
    }
}

int main () {
    int a[] = {1,2,3,0,0,0};
    int b[] = {2,5,6};
    int m = 3;
    int n = 3;
    
    mergeSortedArray(a,b,m,n);
}