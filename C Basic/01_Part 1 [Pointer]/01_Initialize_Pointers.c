# include <stdio.h>

int main () {
    int num, *ptr;
    
    num = 20;
    ptr = &num;

    printf("The value of num is: %d \n", *ptr);
    printf("The value of the pointer is: %d \n", ptr);

    return 0;
}