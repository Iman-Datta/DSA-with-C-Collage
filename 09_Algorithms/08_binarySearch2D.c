# include <stdio.h>
# include <stdbool.h>

# define MAX 100

bool binarySearch2D(int arr[MAX][MAX], int rows, int cols, int target){
    int left = 0;
    int right = rows * cols - 1;
    
    while (left <= right){
        int mid = left + (right - left)/2;

        int row = mid/cols;
        int col = mid%cols;

        if(arr[row][col] == target){
            printf("Element found at position (%d, %d)\n", row, col);
            return true;
        }
        else if (arr[row][col] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

int main ()  {
    int arr[MAX][MAX]; // 2D array
    int rows, cols, target;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

   printf("Enter elements in sorted row-major order:\n");
   for(int i = 0; i < rows; i++){
       for(int j =0; j< cols; j++){
            printf("arr[(%d, %d)]: ", i, j);
            scanf("%d", &arr[i][j]);
       }
   }

    printf("Enter the value of X: ");
    scanf("%d", &target);

    if (!binarySearch2D(arr, rows, cols, target)) {
        printf("Element not found\n");
    }
    return 0;
}