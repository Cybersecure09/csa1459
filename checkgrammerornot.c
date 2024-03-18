#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    // Check if the input string satisfies the grammar rules
    // Implement your grammar checking logic here

    // Example: Check if the input contains a subject, verb, and object
    // This is a simple example and can be expanded based on your grammar rules

    // Display the result
    if (/* Condition to check if input satisfies grammar */) {
        printf("Input string satisfies the grammar rules.\n");
    } else {
        printf("Input string does not satisfy the grammar rules.\n");
    }

    return 0;
}
