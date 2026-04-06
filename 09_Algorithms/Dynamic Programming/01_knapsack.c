#include <stdio.h>
#include <string.h>

#define MAX 100

// --------------------------------------------------
// Part 1: Recursive Approach
// --------------------------------------------------
int knapsackRecursive(int wt[], int val[], int n, int C) {
    // Base case
    if (n == 0 || C == 0)
        return 0;

    // If current item's weight is more than capacity
    if (wt[n - 1] > C)
        return knapsackRecursive(wt, val, n - 1, C);

    // Include or exclude current item
    int include = val[n - 1] +
                  knapsackRecursive(wt, val, n - 1, C - wt[n - 1]);

    int exclude = knapsackRecursive(wt, val, n - 1, C);

    return (include > exclude) ? include : exclude;
}

// --------------------------------------------------
// Part 2: Top-Down Approach (Memoization)
// --------------------------------------------------
int dp[MAX][MAX];

int knapsackMemo(int wt[], int val[], int n, int C) {
    // Base case
    if (n == 0 || C == 0)
        return 0;

    // If already calculated
    if (dp[n][C] != -1)
        return dp[n][C];

    if (wt[n - 1] > C)
        return dp[n][C] = knapsackMemo(wt, val, n - 1, C);

    int include = val[n - 1] +
                  knapsackMemo(wt, val, n - 1, C - wt[n - 1]);

    int exclude = knapsackMemo(wt, val, n - 1, C);

    return dp[n][C] = (include > exclude) ? include : exclude;
}

// --------------------------------------------------
// Part 3: Bottom-Up Approach (Tabulation)
// --------------------------------------------------
int knapsackTabulation(int wt[], int val[], int n, int C) {
    int table[MAX][MAX];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= C; w++) {

            if (i == 0 || w == 0)
                table[i][w] = 0;

            else if (wt[i - 1] <= w) {
                int include = val[i - 1] + table[i - 1][w - wt[i - 1]];
                int exclude = table[i - 1][w];

                table[i][w] = (include > exclude) ? include : exclude;
            }

            else {
                table[i][w] = table[i - 1][w];
            }
        }
    }

    return table[n][C];
}

// --------------------------------------------------
// Main Function
// --------------------------------------------------
int main() {
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int n = 4;
    int C = 7;

    printf("Recursive: %d\n", knapsackRecursive(wt, val, n, C));

    memset(dp, -1, sizeof(dp));
    printf("Memoization: %d\n", knapsackMemo(wt, val, n, C));

    printf("Tabulation: %d\n", knapsackTabulation(wt, val, n, C));

    return 0;
}