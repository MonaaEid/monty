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
        
       /*printf("Elements in stack after popping: ");*/
        /*display();*/
    } else if (argv[1]){
        fprintf(stderr, "L<%s>: usage: push integer\n", argv[1]);
        return(EXIT_FAILURE);
    }
    return (0);
}
