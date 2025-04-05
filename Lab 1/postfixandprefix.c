#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>  // Include this header for exit()

#define MAX 100

// Stack structure for operations
typedef struct {
    char items[MAX];
    int top;
} Stack;

// Stack operations
void push(Stack* s, char item) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);  // Properly exit on overflow
    }
    s->items[++s->top] = item;
}

char pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);  // Properly exit on underflow
    }
    return s->items[s->top--];
}

char peek(Stack* s) {
    if (s->top == -1) return '\0';
    return s->items[s->top];
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

// Helper functions
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Infix to Postfix Conversion
void infixToPostfix(char* infix, char* postfix) {
    Stack s = {.top = -1};
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++) { 
        postfix[k+1] = '\0';
        for(int i=0;postfix[i] !='\0';i++)
        printf(" %c ",postfix[i]);
        char ch = infix[i];

        if (isalnum(ch)) {  // Operand
            postfix[k++] = ch;
        } else if (ch == '(') {  // Left parenthesis
            push(&s, ch);
        } else if (ch == ')') {  // Right parenthesis
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s);  // Remove '('
        } else if (isOperator(ch)) {  // Operator
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[k++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';
}

// Reverse a string
void reverseString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Infix to Prefix Conversion
void infixToPrefix(char* infix, char* prefix) {
    char reversed[MAX];
    strcpy(reversed, infix);
    reverseString(reversed);

    // Replace '(' with ')' and vice versa
    for (int i = 0; reversed[i] != '\0'; i++) {
        if (reversed[i] == '(') reversed[i] = ')';
        else if (reversed[i] == ')') reversed[i] = '(';
    }

    char postfix[MAX];
    infixToPostfix(reversed, postfix);

    // Reverse postfix to get prefix
    strcpy(prefix, postfix);
    reverseString(prefix);
}

// Display operands in a growing box
void displayOperandsInBox(char* infix) {
    printf("\nOperands in a growing box format:\n");

    char buffer[MAX] = "";  // To build the growing sequence of operands
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {  // Check if the character is an operand
            strncat(buffer, &infix[i], 1);  // Append the operand to the buffer
            int length = strlen(buffer);

            // Draw the box for the current sequence
            for (int row = 0; row < 3; row++) {  // Draw top, middle, and bottom
                if (row == 0 || row == 2) {  // Top and bottom borders
                    printf("+");
                    for (int j = 0; j < length; j++) printf("---+");
                    printf("\n");
                } else {  // Middle (content row)
                    printf("|");
                    for (int j = 0; j < length; j++) printf(" %c |", buffer[j]);
                    printf("\n");
                }
            }
        }
    }
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];
    int choice;


    printf("Enter an infix expression: ");
    scanf("%s", infix);



    do {
        printf("\nChoose an option:\n");
        printf("1. Display Operands in a Growing Box\n");
        printf("2. Convert to Postfix\n");
        printf("3. Convert to Prefix\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayOperandsInBox(infix);
                break;

            case 2:
                infixToPostfix(infix, postfix);
                printf("Postfix Expression: %s\n", postfix);
                break;

            case 3:
                infixToPrefix(infix, prefix);
                printf("Prefix Expression: %s\n", prefix);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
