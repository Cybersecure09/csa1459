#include <stdio.h>
#include <ctype.h>

char input[100];
int i = 0;

void E();
void T();
void F();

void E() {
    T();
    while (input[i] == '+' || input[i] == '-') {
        i++;
        T();
    }
}

void T() {
    F();
    while (input[i] == '*' || input[i] == '/') {
        i++;
        F();
    }
}

void F() {
    if (isalnum(input[i])) {
        i++;
    } else if (input[i] == '(') {
        i++;
        E();
        if (input[i] == ')') {
            i++;
        } else {
            printf("Syntax error: Missing closing parenthesis\n");
            return;
        }
    } else {
        printf("Syntax error: Invalid expression\n");
        return;
    }
}

int main() {
    printf("Enter the string: ");
    scanf("%s", input);

    E();

    if (input[i] == '\0') {
        printf("String is successfully parsed\n");
    } else {
        printf("Syntax error: Incomplete expression\n");
    }

    return 0;
}
