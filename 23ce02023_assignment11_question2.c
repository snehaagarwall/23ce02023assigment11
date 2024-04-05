#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeDuplicates(char* s) {
    int length = strlen(s);
    char* stack = (char*)malloc((length + 1) * sizeof(char)); // Allocate memory for stack
    int top = -1; // Stack top pointer

    for (int i = 0; i < length; i++) {
        if (top >= 0 && stack[top] == s[i]) {
            top--; // Remove the duplicate
        } else {
            stack[++top] = s[i]; // Push non-duplicate character onto the stack
        }
    }

    // Null-terminate the final string
    stack[top + 1] = '\0';

    return stack;
}

int main() {
    char s[] = "abbaca";
    char* result = removeDuplicates(s);
    printf("Output: %s\n", result);
    free(result); // Free memory allocated for the result
    return 0;
}