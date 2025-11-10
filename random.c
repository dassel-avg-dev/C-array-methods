#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandom(int min, int max) {
    srand(time(NULL));
    max = (min > max) ? min : max;

    int num = (rand() % (max - min + 1)) + min;
    return num;
}
int main() {

    printf("%d\n", generateRandom(10, 50));
    printf("%d\n", generateRandom(10, 50));
    printf("%d\n", generateRandom(10, 50));
    printf("%d\n", generateRandom(10, 50));
    printf("%d\n", generateRandom(10, 50));
    printf("%d\n", generateRandom(10, 50));
    printf("%d\n", generateRandom(10, 50));

    return 0;
}