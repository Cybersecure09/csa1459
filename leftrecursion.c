#include <stdio.h>
#include <string.h>

void eliminateLeftRecursion(char non_terminal, char production[][10], int n) {
    int i;
    char new_production[10][10], alpha[10][10], beta[10][10];
    int alpha_count = 0, beta_count = 0;

    for (i = 0; i < n; i++) {
        if (production[i][0] == non_terminal) {
            if (production[i][3] == non_terminal) {
                strcpy(beta[beta_count++], production[i] + 4);
            } else {
                strcpy(alpha[alpha_count++], production[i] + 3);
            }
        }
    }

    if (beta_count == 0) {
        printf("The given grammar does not have left recursion for %c\n", non_terminal);
        return;
    }

    printf("After eliminating left recursion for %c:\n", non_terminal);
    for (i = 0; i < alpha_count; i++) {
        printf("%c->%s%c'\n", non_terminal, alpha[i], non_terminal);
    }
    for (i = 0; i < beta_count; i++) {
        printf("%c'->%s%c'\n", non_terminal, beta[i], non_terminal);
    }
    printf("%c'->ε\n", non_terminal);
}

int main() {
    char production[10][10];
    int n, i;
    char non_terminal;

    printf("Enter the number of productions: ");
    scanf("%d", &n);

    printf("Enter the productions:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", production[i]);
    }

    printf("Enter the non-terminal to eliminate left recursion for: ");
    scanf(" %c", &non_terminal);

    eliminateLeftRecursion(non_terminal, production, n);

    return 0;
}
