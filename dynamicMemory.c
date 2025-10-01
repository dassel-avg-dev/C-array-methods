#include <stdio.h>
#include <stdlib.h> // include to use the functions

int getInt();
void input(int* arr, int size);
void display(int* arr, int size);

int main() {
    /*
        malloc (memory allocation) - allocates memory from 
        the heap (a free pool of memory that is outside the stack)
        - returns a void pointer
    */ 
    int size;

    printf("Enter the size of the aray: ");
    size = getInt();

    int* array = (int*)malloc(size * sizeof(int));
    // make sure to check if its empty or not
    if(array == NULL) {
        printf("Malloc failed!\n");
    } 
    else {
        printf("Enter elements\n");
        for(int i=0; i<size; i++) {
            array[i] = getInt();
        }
        display(array, size);
    }
    free(array);

    return 0;
}

int getInt() {
    int n;
    scanf("%d",&n);
    return n;
}

void input(int* arr, int size) {
    for(int i=0; i<size; i++) {
        scanf("%d",&arr[i]);
    }
}

void display(int* arr, int size) {
    for(int i=0; i<size; i++) {
        printf("%d ",arr[i]);
    }
}