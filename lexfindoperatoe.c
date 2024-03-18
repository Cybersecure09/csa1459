#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define PLUS 1
#define MINUS 2
#define MULTIPLY 3
#define DIVIDE 4
int lexAnalyzer(char op) {
    switch(op) {
        case '+':
            return PLUS;
        case '-':
            return MINUS;
        case '*':
            return MULTIPLY;
        case '/':
            return DIVIDE;
        default:
            return 0; // Invalid operator
    }
}
int main() {
    char operator;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);

    int token = lexAnalyzer(operator);

    if(token != 0) {
        printf("Valid operator detected: ");
        switch(token) {
            case PLUS:
                printf("+\n");
                break;
            case MINUS:
                printf("-\n");
                break;
            case MULTIPLY:
                printf("*\n");
                break;
            case DIVIDE:
                printf("/\n");
                break;
        }
    } else {
        printf("Invalid operator entered.\n");
    }

    return 0;
}
