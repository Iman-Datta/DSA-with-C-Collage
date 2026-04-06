#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

// ------------------------------------
// 1. Recursive Approach (Brute Force)
// ------------------------------------
bool subsetSumRecursive(int arr[], int n, int sum) {
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    if (arr[n - 1] > sum)
        return subsetSumRecursive(arr, n - 1, sum);

    return subsetSumRecursive(arr, n - 1, sum) ||
           subsetSumRecursive(arr, n - 1, sum - arr[n - 1]);
}

// ------------------------------------
// 2. Memoization (Top-Down DP)
// ------------------------------------
int memo[MAX][MAX];

bool subsetSumMemo(int arr[], int n, int sum) {
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    if (memo[n][sum] != -1)
        return memo[n][sum];

    if (arr[n - 1] > sum)
        return memo[n][sum] = subsetSumMemo(arr, n - 1, sum);

    return memo[n][sum] =
        subsetSumMemo(arr, n - 1, sum) ||
        subsetSumMemo(arr, n - 1, sum - arr[n - 1]);
}

// ------------------------------------
// 3. Tabulation (Bottom-Up DP)
// ------------------------------------
bool subsetSumTabulation(int arr[], int n, int sum) {
    bool dp[MAX][MAX];

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int j = 1; j <= sum; j++)
        dp[0][j] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] ||
                           dp[i - 1][j - arr[i - 1]];
        }
    }

    return dp[n][sum];
}

// ------------------------------------
// 4. Backtracking to Print All Solutions
// ------------------------------------
void printSubset(int subset[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++)
        printf("%d ", subset[i]);
    printf("}\n");
}

void subsetBacktracking(int arr[], int n, int index,
                        int target, int subset[], int size) {
    if (target == 0) {
        printSubset(subset, size);
        return;
    }

    if (index == n || target < 0)
        return;

    // Include current element
    subset[size] = arr[index];
    subsetBacktracking(arr, n, index + 1,
                       target - arr[index],
                       subset, size + 1);

    // Exclude current element
    subsetBacktracking(arr, n, index + 1,
                       target, subset, size);
}

// ------------------------------------
// Main Function
// ------------------------------------
int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 9;

    memset(memo, -1, sizeof(memo));

    printf("Recursive: %s\n",
           subsetSumRecursive(arr, n, sum) ? "True" : "False");

    printf("Memoization: %s\n",
           subsetSumMemo(arr, n, sum) ? "True" : "False");

    printf("Tabulation: %s\n",
           subsetSumTabulation(arr, n, sum) ? "True" : "False");

    printf("\nAll possible subsets:\n");
    int subset[MAX];
    subsetBacktracking(arr, n, 0, sum, subset, 0);

    return 0;
}