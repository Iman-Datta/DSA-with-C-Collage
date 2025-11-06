// Implement a function to evaluate a postfix expression using a stack.

#include <stdio.h>
#include <ctype.h> // for isdigit()

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}

// Pop function
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Evaluate postfix expression
int evaluatePostfix(char expr[]) {
    int i = 0;
    char token;
    int val1, val2;

    while (expr[i] != '\0') {
        token = expr[i];

        if (isdigit(token)) {
            // Convert character digit to integer
            push(token - '0');
        } 
        else if (token == '+' || token == '-' || token == '*' || token == '/') {
            val2 = pop();
            val1 = pop();

            switch (token) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
        i++;
    }

    return pop();
}

int main() {
    char expr[MAX];

    printf("Enter postfix expression (no spaces, single digits): ");
    scanf("%s", expr);

    int result = evaluatePostfix(expr);
    printf("Result = %d\n", result);

    return 0;
}
