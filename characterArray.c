#include <stdio.h>

int main() {
    char str[] = {'J', 'o', 'h', 'n'}; // initialize by character
    char str2[] = "John"; // initialize via string literal
    int i;
    for(i=0; str[i]!='\0'; i++) { // iterate
        printf("%c",str[i]);
    }

    return 0;
}