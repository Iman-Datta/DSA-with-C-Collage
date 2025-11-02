# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

bool colSearch(int mat[][4],int rows,int cols,int target){
    int start = 0, end = cols - 1;
    while (start <= end) {
        int mid = start + (end - start)/2;
        if (target == mat[rows][mid]){
            return true;
        }
        else if(target < mat[rows][mid]){
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return false;
}

bool searchMatrix(int mat[][4], int rows, int cols, int target) {
    int stRow = 0, endRow = rows - 1;

    while (stRow <= endRow) {
        int midRow = stRow + (endRow - stRow)/2;
        if (target >= mat[midRow][0] && target <= mat[midRow][cols -1]){
            return colSearch(mat, midRow, cols, target);
        }
        else if(target < mat[midRow][0]){
            endRow = midRow - 1;
        }
        else{
            stRow = midRow + 1;
        }
    }
    return false;
}

int main () {
    int target;
    int matrix[3][4] = {
        {1,3,4,5},
        {6,7,9,11},
        {14,21,32,55},
    };
    
    printf("Enter number to search: ");
    scanf("%d", &target);

    if (searchMatrix(matrix, 3, 4, target)) {
        printf("%d found in the matrix.\n", target);
    } else {
        printf("%d not found in the matrix.\n", target);
    }

    return 0;
}