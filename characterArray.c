#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int isPalindrome(char* s, int size) {
    int left = 0, right = size - 1;
    while(left < right) {
        if(s[left] != s[right]) {
            return 0; // false
        }
    }
    return 1;
}

int main() {
    char str[] = {'J', 'o', 'h', 'n'}; // initialize by character
    char str2[] = "John"; // initialize via string literal
    char str3[MAX_SIZE];
    
    int i;
    for(i=0; str[i] != '\0'; i++) { // iterate
        printf("%c",str[i]);
    }
    printf("\n");

    printf("Enter a string: ");
    fgets(str3, MAX_SIZE, stdin);

    // remove null terminator
    str3[strlen(str3) - 1] = '\0';
    int size = strlen(str3);

    return 0;
}