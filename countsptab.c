#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    int whitespace_count = 0;
    int newline_count = 0;

    file = fopen("input.txt", "r"); // Open the input file

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ') {
            whitespace_count++;
        } else if (ch == '\n') {
            newline_count++;
        }
    }

    fclose(file); // Close the file

    printf("Number of whitespaces: %d\n", whitespace_count);
    printf("Number of newline characters: %d\n", newline_count);

    return 0;
}
