#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i;
    int value;
    struct stack_s* top = NULL;
    if (argc > 1)
    {
        for (i = 1; i < argc; i++) {
            value = atoi(argv[i]);
            push(&top, value);
        }
        
        printf("Elements in stack: ");
        /*display();*/
        
       /* pop();*/
        
        printf("Elements in stack after popping: ");
        /*display();*/
    } else {
        printf("No arguments provided\n");
    }
    return (0);
}