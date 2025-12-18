#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
	Stack s1 = createStack();
	Stack s2 = createStack();
	// stack 1
	push(s1, 1);
	push(s1, 2);
	push(s1, 3);
	// stack 2
	push(s2, 1);
	push(s2, 2);
	push(s2, 3);

	display(s1);
	display(s2);
	
	printf((isEqual(s1, s2)) ? "Equal\n" : "Not equal\n");
	return 0;
}
