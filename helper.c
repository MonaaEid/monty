#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/*void opcode_function(stack_t **stack, unsigned int line_number)*/
struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}


int isEmpty(struct Node* top) {
    return top == NULL;
}


void push(struct Node** top, int data) {
    struct Node* node = newNode(data);
    node->next = *top;
    *top = node;
    printf("%d pushed to stack\n", data);
}

int pop(struct Node** top) 
{
	struct Node* temp;
	int popped;
	
    if (isEmpty(*top)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    temp = *top;
    *top = (*top)->next;
    popped = temp->data;
    free(temp);
    return popped;
}
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
void display(struct Node* top) 
{
	struct Node* temp;
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }
    temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    printf("Elements in stack: ");
    display(top);

    printf("Popped element: %d\n", pop(&top));
    
    printf("Elements in stack after popping: ");
    display(top);

    return 0;
}
