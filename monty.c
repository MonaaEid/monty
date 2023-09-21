#include "monty.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>

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
    } else if (argc <= 1){
        fprintf(stderr, "L<%s>: usage: push integer\n", argv[1]);
        return(EXIT_FAILURE);
    }
    return (0);
}
