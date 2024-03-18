#include <stdio.h>
#include <ctype.h>
#include <string.h>


int isOperator(char ch) {
    char operators[] = "+-*/=";
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i]) {
            return 1;
        }
    }
    return 0;
}


int isDelimiter(char ch) {
    char delimiters[] = " \t\n";
    for (int i = 0; i < strlen(delimiters); i++) {
        if (ch == delimiters[i]) {
            return 1;
        }
    }
    return 0;
}

void lexicalAnalyzer(char input[]) {
    int i = 0;
    while (input[i] != '\0') {
       
        if (isDelimiter(input[i])) {
            i++;
            continue;
        }
        
        if (input[i] == '/' && input[i + 1] == '/') {
            break;
        }

        if (isalpha(input[i])) {
            printf("Identifier: ");
            while (isalnum(input[i])) {
                printf("%c", input[i]);
                i++;
            }
            printf("\n");
        }

        else if (isdigit(input[i])) {
            printf("Constant: ");
            while (isdigit(input[i])) {
                printf("%c", input[i]);
                i++;
            }
            printf("\n");
        }

        else if (isOperator(input[i])) {
            printf("Operator: %c\n", input[i]);
            i++;
        } else {
            i++;
        }
    }
}
int main() {
    char input[] = "int a = 10; // This is a comment";
    
    lexicalAnalyzer(input);
    
    return 0;
}
