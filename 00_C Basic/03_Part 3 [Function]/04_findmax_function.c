# include <stdio.h>
# define SIZE 100

int findMax(int n){
    int arr[SIZE], max;

    printf("Give the element input of the array: \n");
    for(int i = 0; i < n; i++){
        printf("%d element: ", i+1);
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    for(int i = 1; i < n; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

int main () {
    int num, max_num;
    printf("Enter the size of the array: ");
    scanf("%d", &num);

    max_num = findMax(num);
    printf("The maximum element of the array is: %d \n", max_num);
    return 0;
}