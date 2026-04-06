#include <stdio.h>
#include <stdbool.h>

#define MAX 20

// Print the chessboard
void printBoard(int board[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Check whether queen can be placed safely
bool isSafe(int board[MAX][MAX], int row, int col, int n) {
    int i, j;

    // Check left side of same row
    for (i = 0; i < col; i++) {
        if (board[row][i] == 1)
            return false;
    }

    // Check upper-left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check lower-left diagonal
    for (i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Backtracking function
bool solveNQueen(int board[MAX][MAX], int col, int n) {
    // Base case: all queens placed
    if (col == n)
        return true;

    for (int row = 0; row < n; row++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;   // place queen

            if (solveNQueen(board, col + 1, n))
                return true;

            board[row][col] = 0;   // backtrack
        }
    }

    return false;
}

// Main function
int main() {
    int n;
    int board[MAX][MAX] = {0};

    printf("Enter value of N: ");
    scanf("%d", &n);

    if (solveNQueen(board, 0, n)) {
        printf("\nSolution found:\n");
        printBoard(board, n);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}