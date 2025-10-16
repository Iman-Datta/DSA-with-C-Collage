# include <stdio.h>

int main() {
    int a = 10, b = 20, c = 30;
    int *arr[] = {
        &a, &b, &c
    };
    char *names[] = {
        "aa", "bb", "cc" // String literals => Read only segments block
    };

    for (int i = 0; i < 3; i++) {
        printf("%d \n", *arr[i]);
        printf("%s \n", names[i]);
    }

    return 0;
}