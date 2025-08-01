# include <stdio.h>

int main () {
    int num;
    num = 20;

    int *ptr;
    ptr = &num;
    printf("The value of num is: %d \n", *ptr); // *ptr indicate the value of the variable
    printf("The value of the pointer is: %d \n", ptr); // ptr has the adreess of the variable

    *ptr = 88; 
    printf("The modified value of the variable using pointer: %d \n", *ptr);

    return 0;
}