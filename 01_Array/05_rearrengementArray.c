// Rearrange the array such that all posetive number appear before negetive number

# include <stdio.h>

void rearrange(int arr[], int n){
    int left = 0, right = n -1;
    while (left <= right){
        if(arr[left] > 0 && arr[right] < 0){ // left is +ve and right is -ve
            left ++;
            right --;
        }
        else if (arr[left] > 0 && arr[right] > 0){ // both are +ve
            left ++;
        }
        else if (arr[left] < 0 && arr[right] < 0){ // both are -ve
            right --;
        }
        else{ // left is -ve and right is +ve → swapl
            int temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
            left++;
            right--;
        }
    }

    printf("Rearranged array: ");
    for (int i = 0; i < n; i++) {
        printf("%d \t", arr[i]);
    }
}

int main (){
    int arr[] = {-1,2,3,-4,1,-5,10,5,-33};
    int sz = sizeof(arr)/sizeof(arr[0]);

    printf("The original array: ");
    for(int i = 0; i <= sz -1; i++){
        printf("%d \t", arr[i]);
    }
    printf("\n");

    rearrange(arr,sz);

    return 0;
}