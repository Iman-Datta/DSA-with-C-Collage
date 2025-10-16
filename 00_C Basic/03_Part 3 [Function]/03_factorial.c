# include <stdio.h>

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    else{
        return(n * factorial(n-1));
    }
}

int main (){ 
    int num, result;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Give input a posetive number");
        return 0;
    }
    else {
        result = factorial(num);
        printf("The factorial of %d is: %d",num, result );
    }
    return 0;
}