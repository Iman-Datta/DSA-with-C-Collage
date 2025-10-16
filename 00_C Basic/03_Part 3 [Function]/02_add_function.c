# include <stdio.h>

int sum(int x, int y){
    return x+y;
}

int main () {
    int a,b, result;
    printf("Enter the 1st number: ");
    scanf("%d", &a);
    printf("Enter the 2nd number: ");
    scanf("%d", &b);

    result = sum(a,b);
    printf("The sum of that two number is: %d", result);
}
