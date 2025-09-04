#include <stdio.h>

void input(int arr[], int size);
void display(int arr[], int size);
int computeSum(int arr[], int size);
int countPos(int arr[], int size);
int countNeg(int arr[], int size);
int countEven(int arr[], int size);
int countOdd(int arr[], int size);
int findItem(int arr[], int size, int item);
int findMax(int arr[], int size);
int findMin(int arr[], int size);
int isPalindrome(int arr[], int size);
void add(int arr[], int* count, int item);
void addFrontV1(int arr[], int* count, int item);
void addFrontV2(int arr[], int* count, int item);
void addAtV1(int arr[], int* count, int item, int pos);
void addAtV2(int arr[], int* count, int item, int pos);
void deleteEnd(int* count);
void deleteFrontV1(int arr[], int* count);
void deleteFrontV2(int arr[], int* count);
void deleteAtV1(int arr[], int* count, int pos);
void deleteAtV2(int arr[], int* count, int pos);

int main() {
    int arr[] = {1, 2, 3, 4, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int* count = &size;

    display(arr, size);
    addFrontV2(arr, count, 6);

    display(arr, size);
    addAtV1(arr, count, 10, 3);
    
    display(arr, size);
    addAtV2(arr, count, 100, 2);
    
    display(arr, size);
    deleteEnd(count);
    display(arr, size);
    
    deleteFrontV1(arr, count);
    display(arr, size);
    
    deleteFrontV2(arr, count);
    display(arr, size);
    
    deleteAtV1(arr, count, 3);
    display(arr, size);

    deleteAtV2(arr, count, 2);
    display(arr, size);

    return 0;
}

void input(int arr[], int size) {
    int i;
    for(i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
}

void display(int arr[], int size) {
    int i;
    printf("[");
    for(i=0; i<size; i++) {
        printf("%d", arr[i]);
        if(i < size - 1) {
            printf(", ");
        }
    }
    printf("] ");
    printf("\n");
}

int computeSum(int arr[], int size) {
    int i, sum=0;
    for(i=0; i<size; i++) {
        sum+=arr[i];
    }
    return sum;
}

int countPos(int arr[], int size) {
    int i, posCount=0;
    for(i=0; i<size; i++) {
        if(arr[i] > 0) {
            posCount++;
        }
    }
    return posCount;
}

int countNeg(int arr[], int size) {
    int i, negCount=0;
    for(i=0; i<size; i++) {
        if(arr[i] < 0) {
            negCount++;
        }
    }
    return negCount;
}

int countEven(int arr[], int size) {
    int i, evenCount=0;
    for(i=0; i<size; i++) {
        if(arr[i] % 2 == 0) {
            evenCount++;
        }
    }
    return evenCount;
}

int countOdd(int arr[], int size) {
    int i, oddCount=0;
    for(i=0; i<size; i++) {
        if(arr[i] % 2 != 0) {
            oddCount++;
        }
    }
    return oddCount;
}

int findItem(int arr[], int size, int item) {
    int i, found=0;
    for(i=0;i<size; i++) {
        if(arr[i] == item) {
            found = 1;
            break;
        }
    }
    return found;
}

int findMax(int arr[], int size) {
    int i, max = arr[0];
    for(i=1; i<size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMin(int arr[], int size) {
    int i, min = arr[0];
    for(i=1; i<size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int isPalindrome(int arr[], int size) {
    int i, palindrome=1;
    for(i=0; i<size/2; i++) {
        if(arr[i]!=arr[size-1-i]) {
            palindrome = 0; 
            break;
        }
    }
    return palindrome;
}

void add(int arr[], int* count, int item) {
    arr[(*count)++] = item;
}

void addFrontV1(int arr[], int* count, int item) {
    int i;
    for(i = *count; i>0; i--) {
        arr[i] = arr[i - 1]; // shift elements to the right until index 1;
    }
    arr[0] = item;
    (*count)++;
}

void addFrontV2(int arr[], int* count, int item) {
    int i;
    for(i = *count - 1; i>=0; i--) { // shift elements to the right up to index zero
        arr[i+1] = arr[i];
    }
    arr[0] = item;
    (*count)++;
}

void addAtV1(int arr[], int* count, int item, int pos) {
    int i;
    for(i= *count; i>pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = item;
    (*count)++;
}

void addAtV2(int arr[], int* count, int item, int pos) {
    int i;
    for(i= *count - 1; i>=pos; i--) {
        arr[i+1] = arr[i];
    }
    arr[pos] = item;
    (*count)++;
}

void deleteEnd(int* count) {
    (*count)--;
}

void deleteFrontV1(int arr[], int* count) {
    int i;
    for(i=0; i<(*count)-1; i++) {
        arr[i] = arr[i+1];
    }
    (*count)--;
}

void deleteFrontV2(int arr[], int* count) {
    int i;
    for(i=1; i<(*count); i++) {
        arr[i-1] = arr[i];
    }
    (*count)--;
}

void deleteAtV1(int arr[], int* count, int pos) {
    int i;
    for(i=pos; i<(*count)-1; i++) {
        arr[i] = arr[i+1];
    }
    (*count)--;
}

void deleteAtV2(int arr[], int* count, int pos) {
    int i;
    for(i=pos+1; i<(*count); i++) {
        arr[i-1] = arr[i];
    }
    (*count)--;
}




