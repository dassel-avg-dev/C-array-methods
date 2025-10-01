#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100

typedef char String[MAX_SIZE];

// Function to convert a string to lowercase
void toLowerCase(char* str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

char flamesCompare(char* nameOne, char* nameTwo) {
    char flames[7] = "FLAMES";

    int name1Len = strlen(nameOne);
    int name2Len = strlen(nameTwo);

    // Removing spaces and converting to lowercase
    char tempNameOne[MAX_SIZE], tempNameTwo[MAX_SIZE];
    int indexOne = 0, indexTwo = 0;

    for(int i = 0; i < name1Len; i++) {
        if(nameOne[i] != ' ') {
            tempNameOne[indexOne++] = nameOne[i];
        }
    }
    tempNameOne[indexOne] = '\0';

    for(int i = 0; i < name2Len; i++) {
        if(nameTwo[i] != ' ') {
            tempNameTwo[indexTwo++] = nameTwo[i];
        }
    }
    tempNameTwo[indexTwo] = '\0';

    // Convert both names to lowercase
    toLowerCase(tempNameOne);
    toLowerCase(tempNameTwo);

    name1Len = strlen(tempNameOne);
    name2Len = strlen(tempNameTwo);

    for(int i = 0; i < name1Len; i++) {
        for(int j = 0; j < name2Len; j++) {
            if(tempNameOne[i] == tempNameTwo[j]) {
                tempNameOne[i] = tempNameTwo[j] = '\0'; // mark as removed
                name1Len--;
                name2Len--;
            }
        }
    }

    int res = (name1Len + name2Len) % 6; // We use modulo to handle wraparound in FLAMES
    return flames[res];
}

int main() {
    String nameOne, nameTwo;

    printf("Enter name one: ");
    fgets(nameOne, sizeof(nameOne), stdin);
    nameOne[strcspn(nameOne, "\n")] = '\0';
    
    printf("Enter name two: ");
    fgets(nameTwo, sizeof(nameTwo), stdin);
    nameTwo[strcspn(nameTwo, "\n")] = '\0';

    char result = flamesCompare(nameOne, nameTwo);

    switch(result) {
        case 'F':
            printf("Friends\n");
            break;
        case 'L':
            printf("Lovers\n");
            break;
        case 'A':
            printf("Adversaries\n");
            break;
        case 'M':
            printf("Married\n");
            break;
        case 'E':
            printf("Enemies\n");
            break;
        case 'S':
            printf("Sweethearts\n");
            break;
        default:
            printf("Invalid\n");
    }

    return 0;
}
