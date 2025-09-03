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
    printf("[ ");
    for(i=0; i<size; i++) {
        printf("%d", arr[i]);
        if(i < size) {
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




