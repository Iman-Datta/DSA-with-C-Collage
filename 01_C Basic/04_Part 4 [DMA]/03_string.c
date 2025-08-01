# include <stdio.h>
# include <stdlib.h>

int main (){
    char *str;
    int size = 100;
    
    str = (char*)malloc(sizeof(char));

    printf("Enter your name: ");
    fgets(str, size, stdin);

    printf("\n Your name is: %s", str);

    free(str);
    return 0;
}