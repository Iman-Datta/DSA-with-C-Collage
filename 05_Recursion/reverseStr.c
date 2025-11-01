// Write a function to reverse a string using recursion


#include <stdio.h>
#include <string.h>

// Function to reverse a string using recursion
void reverseString(char str[], int start, int end) {
    if (start >= end) {
        return; // Base case: stop when start crosses end
    }

    // Swap characters at start and end
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call for the remaining string
    reverseString(str, start + 1, end - 1);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    gets(str); // Take string input (use fgets in modern C)

    int len = strlen(str);
    reverseString(str, 0, len - 1);

    printf("Reversed string: %s\n", str);

    return 0;
}
