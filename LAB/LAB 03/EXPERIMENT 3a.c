#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1)
        printf("Stack overflow\n");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}

int precedence(char c) {
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    char item;
    int i = 0, k = 0;
    while (infix[i]) {
        item = infix[i];
        if (isalnum(item)) {
            postfix[k++] = item;
        } else if (item == '(') {
            push(item);
        } else if (item == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(item)) {
                postfix[k++] = pop();
            }
            push(item);
        }
        i++;
    }
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    gets(infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
