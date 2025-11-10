#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    List head = createList(5);
    display(head);

    
    free(head);
    return 0;
}