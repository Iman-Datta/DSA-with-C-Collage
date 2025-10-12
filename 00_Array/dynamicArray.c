# include <stdio.h>
# include <stdlib.h>

int main() {
    int *arr, i, n;
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    // scanf("%d", p + 1);
    }

    printf("You entered: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

// 1. *arr is pointer which is declare inside stack.
// 2. The pointer P hold the base address which exist inside the heep memory.
// 3. This address is dynamically allocate by malloc.
// 4. malloc allocated continuous memory block based on n as given by user input