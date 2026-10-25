#include "stack.h"
#include <stdio.h>
#define STACK_SIZE 256


//Function used to initialize the stack
void initialize(Stack *stack)
{
    stack ->top = -1;
}

//Function to check if the stack is empty
int isEmpty(Stack *stack)
{
    return (stack-> top == -1);
}


int isFull(Stack *stack)
{
    return (stack->top == (STACK_SIZE - 1));
}

void push(Stack *stack, char value)
{
    if (isFull(stack))
    {
        printf("Stack is full. Cannot push value: %c\n", value);
        return;
    }
    printf("Adding value %c", value);
    ++(stack-> top);
    (stack->values[(stack->top)]) = value;
}

char pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty. Cannot pop value.\n");
        return '\0';
    }
    char val=(stack -> values[(stack->top)]);
    --(stack->top);
    return val;
}


char peek(Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("Nothing to return stack is empty");
        return '\0';
    }
    return (stack->values[(stack->top)]);
}