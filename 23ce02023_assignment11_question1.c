#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure for stack
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// Function prototypes
void push(Stack *s, char value);
char pop(Stack *s);
int isEmpty(Stack *s);
void reverseString(char *str);

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);
    // Removing newline character from fgets
    str[strcspn(str, "\n")] = '\0';

    reverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}

// Function to push an element onto the stack
void push(Stack *s, char value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = value;
}

// Function to pop an element from the stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to reverse a string using a stack
void reverseString(char *str) {
    Stack stack;
    stack.top = -1;

    // Push each character of the string onto the stack
    for (int i = 0; str[i] != '\0'; i++) {
        push(&stack, str[i]);
    }

    // Pop each character from the stack and put it back into the string
    for (int i = 0; !isEmpty(&stack); i++) {
        str[i] = pop(&stack);
    }
}