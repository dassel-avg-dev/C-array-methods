#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
	Stack s = createStack();
	push(s, 10);
	push(s, 20);
	push(s, 30);
	display(s);
	printf((isEmpty(s)) ? "Stack is empty\n" : "Stack is not empty\n");
	pop(s);
	display(s);
	pop(s);
	display(s);
	pop(s);
	display(s);
	printf((isEmpty(s)) ? "Stack is empty\n" : "Stack is not empty\n");
	push(s, 40);
	display(s);
	printf((isEmpty(s)) ? "Stack is empty\n" : "Stack is not empty\n");
	return 0;
}
