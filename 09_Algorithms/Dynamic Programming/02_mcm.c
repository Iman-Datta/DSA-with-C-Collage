#include <stdio.h>
#include <limits.h>

#define MAX 100

// -----------------------------
// 1. Pure Recursion
// -----------------------------
int mcmRecursive(int arr[], int i, int j) {
    if (i == j)
        return 0;

    int minCost = INT_MAX;

    for (int k = i; k < j; k++) {
        int cost = mcmRecursive(arr, i, k) +
                   mcmRecursive(arr, k + 1, j) +
                   arr[i - 1] * arr[k] * arr[j];

        if (cost < minCost)
            minCost = cost;
    }

    return minCost;
}

// -----------------------------
// 2. Top-Down Memoization
// -----------------------------
int mcmMemo(int arr[], int i, int j, int dp[MAX][MAX]) {
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = INT_MAX;

    for (int k = i; k < j; k++) {
        int cost = mcmMemo(arr, i, k, dp) +
                   mcmMemo(arr, k + 1, j, dp) +
                   arr[i - 1] * arr[k] * arr[j];

        if (cost < dp[i][j])
            dp[i][j] = cost;
    }

    return dp[i][j];
}

// -----------------------------
// 3. Bottom-Up Tabulation
// -----------------------------
int mcmTabulation(int arr[], int n) {
    int dp[MAX][MAX];

    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

    for (int len = 2; len < n; len++) {
        for (int i = 1; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] +
                           dp[k + 1][j] +
                           arr[i - 1] * arr[k] * arr[j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    return dp[1][n - 1];
}

// -----------------------------
// Main Function
// -----------------------------
int main() {
    int arr[] = {10, 20, 30, 40, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    int dp[MAX][MAX];

    // Initialize dp with -1
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            dp[i][j] = -1;
        }
    }

    printf("Using Recursion: %d\n", mcmRecursive(arr, 1, n - 1));
    printf("Using Memoization: %d\n", mcmMemo(arr, 1, n - 1, dp));
    printf("Using Tabulation: %d\n", mcmTabulation(arr, n));

    return 0;
}