#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct Symbol {
    char name[20];
    int value;
};

struct Symbol symbolTable[SIZE];

int hashFunction(char *name) {
    int sum = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        sum += name[i];
    }
    return sum % SIZE;
}

void insertSymbol(char *name, int value) {
    int index = hashFunction(name);
    strcpy(symbolTable[index].name, name);
    symbolTable[index].value = value;
}

void searchSymbol(char *name) {
    int index = hashFunction(name);
    if (strcmp(symbolTable[index].name, name) == 0) {
        printf("Symbol found: %s = %d\n", symbolTable[index].name, symbolTable[index].value);
    } else {
        printf("Symbol not found.\n");
    }
}

int main() {
    insertSymbol("x", 10);
    insertSymbol("y", 20);

    searchSymbol("x");
    searchSymbol("z");

    return 0;
}
