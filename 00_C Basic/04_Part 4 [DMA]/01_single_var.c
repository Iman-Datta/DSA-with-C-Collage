# include <stdio.h>
# include <stdlib.h>

int main () {
    int num, *ptr;

    printf("Enter a number: ");
    scanf("%d", &num);

    ptr = (int*)malloc(sizeof(int));

    if (ptr == NULL){
        printf("Memory allocation failed.\n");
    }
    else{
        ptr = &num;
        printf("The value of the number is: %d", *ptr);
    }

    free(ptr);

    return 0;
}