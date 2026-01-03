#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char* postfix) {
    int i = 0;
    char ch;
    int op1, op2;
    while (postfix[i]) {
        ch = postfix[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            op2 = pop();
            op1 = pop();
            switch(ch) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
        i++;
    }
    return pop();
}

int main() {
    char postfix[MAX];
    printf("Enter postfix expression (single digit operands): ");
    gets(postfix);
    printf("Result = %d\n", evaluatePostfix(postfix));
    return 0;
}
