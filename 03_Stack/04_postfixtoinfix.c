#include <stdio.h>
#include <ctype.h>   // for isalnum()
#include <string.h>  // for strlen()

#define MAX 100

char stack[MAX];
int top = -1;

// Push operator to stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}

// Pop operator from stack
char pop() {
    if (top == -1) {
        // Stack underflow
        return '\0';
    } else {
        return stack[top--];
    }
}

char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Precedence function
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default:  return 0;
    }
}

// Infix to Postfix conversion
void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (ch == ' ') {
            // ignore spaces
            continue;
        }

        if (isalnum(ch)) {
            // Operand → directly add to postfix
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            // Pop until '('
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
            }
            if (!isEmpty() && peek() == '(') {
                pop(); // remove '('
            } else {
                printf("Error: Mismatched parentheses\n");
                return;
            }
        }
        else if (isOperator(ch)) {
            // Pop while stack top has higher or equal precedence
            // For '^' (right associative), we pop only when higher precedence
            while (!isEmpty() && isOperator(peek())) {
                char topOp = peek();
                int pTop = precedence(topOp);
                int pCur = precedence(ch);

                if (pTop > pCur || (pTop == pCur && ch != '^')) {
                    // Pop higher precedence or same-precedence (except '^')
                    postfix[k++] = pop();
                } else {
                    break;
                }
            }
            push(ch);
        }
        else {
            printf("Error: Invalid character '%c'\n", ch);
            return;
        }
    }

    // Pop remaining operators
    while (!isEmpty()) {
        if (peek() == '(') {
            printf("Error: Mismatched parentheses\n");
            return;
        }
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);

    // remove trailing newline if any
    size_t len = strlen(infix);
    if (len > 0 && infix[len - 1] == '\n') {
        infix[len - 1] = '\0';
    }

    infixToPostfix(infix, postfix);

    printf("Postfix: %s\n", postfix);

    return 0;
}
