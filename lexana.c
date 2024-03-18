#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to check if a character is an operator
int isOperator(char ch) {
    char operators[] = "+-*/=";
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i]) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a character is a delimiter
int isDelimiter(char ch) {
    char delimiters[] = " \t\n";
    for (int i = 0; i < strlen(delimiters); i++) {
        if (ch == delimiters[i]) {
            return 1;
        }
    }
    return 0;
}

// Function to analyze the input and identify tokens
void lexicalAnalyzer(char input[]) {
    int i = 0;
    while (input[i] != '\0') {
        // Ignore spaces, tabs, and new lines
        if (isDelimiter(input[i])) {
            i++;
            continue;
        }
        
        // Ignore comments starting with '//'
        if (input[i] == '/' && input[i + 1] == '/') {
            break; // Ignore the rest of the line
        }

        // Identify identifiers
        if (isalpha(input[i])) {
            printf("Identifier: ");
            while (isalnum(input[i])) {
                printf("%c", input[i]);
                i++;
            }
            printf("\n");
        }

        // Identify constants
        else if (isdigit(input[i])) {
            printf("Constant: ");
            while (isdigit(input[i])) {
                printf("%c", input[i]);
                i++;
            }
            printf("\n");
        }

        // Identify operators
        else if (isOperator(input[i])) {
            printf("Operator: %c\n", input[i]);
            i++;
        } else {
            i++;
        }
    }
}

// Main function to test the lexical analyzer
int main() {
    char input[] = "int a = 10; // This is a comment";
    
    lexicalAnalyzer(input);
    
    return 0;
}
