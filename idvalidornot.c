#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidIdentifier(char *identifier) {
    if (!isalpha(identifier[0]) && identifier[0] != '_')
        return 0;

    for (int i = 1; i < strlen(identifier); i++) {
        if (!isalnum(identifier[i]) && identifier[i] != '_')
            return 0;
    }

    if (strlen(identifier) > 31)
        return 0;

    return 1;
}

int main() {
    char identifier[50];
    
    printf("Enter an identifier: ");
    scanf("%s", identifier);

    if (isValidIdentifier(identifier))
        printf("Valid identifier!\n");
    else
        printf("Invalid identifier!\n");

    return 0;
}
