#include <stdio.h>
#define SIZE 500

int getInt() {
    int n;
    scanf("%d",&n);
    return n;
}

void initialize(int twoDmatrix[][SIZE], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            twoDmatrix[i][j] = getInt();
        }
    }    
}

void display(int twoDmatrix[][SIZE], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ",twoDmatrix[i][j]);
        }
        printf("\n");
    }    
    
}

int main() {
    int table[SIZE][SIZE];
    int rows, cols;

    printf("Enter the number of rows: ");
    rows = getInt();

    printf("Enter the number of columns: ");
    cols = getInt();

    initialize(table, rows, cols);
    display(table, rows, cols);


    return 0;
}