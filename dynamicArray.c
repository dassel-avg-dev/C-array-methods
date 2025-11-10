#include <stdio.h>
#include <stdlib.h>

int* createArray(int size);
int* resize(int* arr, int newSize);

int main() {
    int* arr = createArray(10);
    for(int i=0; i<10; i++) {
        arr[i] = i+1;
    }
    for(int i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

int* createArray(int size) {
    int* newNode = (int*)malloc(size * sizeof(int));

    if(!newNode) {
        printf("Malloc Failed!");
        exit(1);
    }

    return newNode;
}

int* resize(int* arr, int newSize) {
    int* newArray = (int*)realloc(arr, newSize * sizeof(int));
    return newArray;
}