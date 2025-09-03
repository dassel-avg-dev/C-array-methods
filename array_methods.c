#include <stdio.h>
#include <stdbool.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Sorting algorithms
void printArray(int arr[], int size) {
    for (int i=0; i<size; i++) {
       printf("LA[%d] = %d\n", i, arr[i]);
    }
    printf("\n");
    
}

void bubbleSort(int* arr, int size) {
    if (size <= 1) return;

    int swapped;
    for (int i=0; i<size; i++) {
        swapped = 0;
        for (int j=0; j<size - 1 - i; i++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }
        }
        if (swapped) {
            break;
        }
    }
}


void selectionSort(int* arr, int size) {
    if (size <= 1) printf("Array is already sorted\n"); return;
    int minIndex;
    for (int i=0; i<size; i++) {
        minIndex = i;
        for (int j=i+1; j<size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

void insertionSort(int* arr, int size) {
    if (size <= 1) return;

    int holePos; // holeposition
    int insertValue;
    for (int i=0; i<size; i++) {
        insertValue = arr[i];
        holePos = i;
        while (holePos > 0 && arr[holePos -1] > insertValue) {
            arr[holePos] = arr[holePos - 1];
            holePos--;
        }
        arr[holePos] = insertValue;
    }
}

void insertAtPosition(int* arr, int* size, int position, int item) {
    if (*size <= 1) return;
    int j = *size - 1;

    while (j > position) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[position] = item;

    (*size)++;
}

void removeAtPosition(int* arr, int* size, int position) {
    int j = position; // j starts at specified index position

    // continue as long as j is less than the array size
    while(j < *size) { 
        arr[j] = arr[j + 1]; // move the current element to the next element
        j++; // increment by one
    }

    (*size)--; // decrease the size
}

void addElement(int* arr, int* size, int item) {
    arr[(*size)++] = item;
}

int searchItemIndex(int* arr, int size, int item) {
    for (int i=0; i<=size; i++) {
        if (arr[i] == item) {
            return i;
        }
    }
    return 0;
}

int binarySearch(int* arr, int size, int target) {
    int left = 0, right = size - 1, found = -1;
    while(left < right) {
        int mid = (right + left) / 2;
        if(arr[mid] == target) {
            found = mid;
            return found;
        }
        else if(arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return found;
}

// overwrite's an existing element with another value
void updateArray(int* arr, int size, int positon, int item) {
    arr[positon - 1] = item;
}

void removeElementByValue(int* arr, int* size, int value) {
    int i, j, removed=0;
    for(i=0; i < *size; i++) {
        if(arr[i] == value) {
            removed = 1;
            for(j=i; j < *size-1; j++) {
                arr[j] = arr[j+1];
            }
            i--;
            (*size)--;
        }
    }
    if(removed) {
        printf("The inputted value has been successfully removed!\n");
    } else {
        printf("Cannot be removed if not found\n");
    }
}

void Main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Linear array:\n");
    printArray(arr, size);
    removeElementByValue(arr, &size, 5);
    
    printf("Updated array:\n");
    printArray(arr, size);

    int found = binarySearch(arr, size, 6);
    printf("Target found at index %d\n",found);
}

int main() { Main(); return 0;}
