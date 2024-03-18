#include <stdio.h>

int main() {
    char input;
    
    printf("Enter 'c' or 'd': ");
    scanf("%c", &input);
    
    if(input == 'c') {
        printf("You entered 'c'\n");
    } else if(input == 'd') {
        printf("You entered 'd'\n");
    } else {
        printf("Invalid input\n");
    }
    
    return 0;
}
