#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct {
    char data[MAX];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push element onto stack
void push(Stack *s, char item) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->data[++(s->top)] = item;
}

// Pop element from stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return s->data[(s->top)--];
}

// Peek at the top element of the stack
char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->data[s->top];
}

// Check if the character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Get precedence of an operator
int precedence(char ch) {
    switch (ch) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Convert infix to postfix with step-by-step output
int infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    initStack(&s);
    int i = 0, j = 0;
    char stackContent[MAX], outputContent[MAX];
    
    printf("+---------------+---------------+---------------+\n");
    printf("| Current Char  | Stack         | Output        |\n");
    printf("+---------------+---------------+---------------+\n");

    while (infix[i] != '\0') {
        char ch = infix[i];

        // Process the character
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);  // Remove '(' from the stack
        } else if (isOperator(ch)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }

        // Prepare stack content for display
        int k;
        for (k = 0; k <= s.top; k++) {
            stackContent[k] = s.data[k];
        }
        stackContent[k] = '\0';

        // Prepare output content for display
        strncpy(outputContent, postfix, j);
        outputContent[j] = '\0';

        // Print formatted output
        printf("| %-13c | %-13s | %-13s |\n", ch, stackContent, outputContent);

        i++;
    }

    // Pop remaining operators from stack
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';

    // Final state of output
    printf("+---------------+---------------+---------------+\n");
    
}

// Reverse a string
void reverseString(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Convert infix to prefix with step-by-step output
void infixToPrefix(char infix[], char prefix[]) {
	printf("\nStep-by-Step Infix to Prefix Conversion:\n");
    reverseString(infix);
    for (int i = 0; infix[i] != '\0'; i++) {
    	
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    
    char temp[MAX];
    infixToPostfix(infix, temp);
    reverseString(temp);
    strcpy(prefix, temp);
}

int main() {

    printf("compiled by Aswin phuyal\n");   
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("\nFinal Postfix expression: %s\n", postfix);

    infixToPrefix(infix, prefix);
    printf("Final Prefix expression: %s\n", prefix);

    return 0;
}