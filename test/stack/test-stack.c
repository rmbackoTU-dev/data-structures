
#include <stdio.h>
#include "stack.h"

int main()
{
    //First make a stack
    Stack stk;
    initialize(&stk);

    //push a bunch of stuff
    char alpha[10]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char *iter=alpha;
    char *end=alpha+10;
    printf("START:");
    printf("    iterator=           %p\n", (void*)iter);
    printf("    Value pointed to by iterator    %c\n", (char)*iter);
    printf("    end of iterator=    %p\n", (void*)end);
    printf("    Value pointed to by end    %c\n", (char)*end);
    printf("\n\tEND!\n");
    int i=0;
    while(iter < end)
    {
        printf("\n\tOn index %d\n", i);
        printf("\tCharacter to push %c\n", *iter);
        push(&stk, *iter);
        iter++;
        i++;
        
    }
    //pop a few things
    char val;
    int index=0;
    while(index <3)
    {
        val=pop(&stk);
        printf("\nThe value popped off was %c\n", val);
        index++;
    }
    //display
    //empty the stack
    int lastPop_index=7;
    int j=0;
    while(j < lastPop_index)
    {
         val=pop(&stk);
         printf("\nThe value popped off was %c\n", val);
         j++;
     }
    
    //check if the stack is empty
    if(isEmpty(&stk))
    {
        printf("We successfully cleared the stack!\n");
    }
    //push 256 things
    for(int k=0; k<256; k++)
    {
        int alpha_index=k%10;
        printf("ALPHA INDEX %d\n", alpha_index );
        push(&stk, alpha[alpha_index]);
        printf("\t\tWe pushed the letter %c\n",alpha[alpha_index]);
        fflush(stdout); //This needs cleaning for some reason
        printf("\nCLEAN +  %d\n", k);
    }
    //check if the stack is full
    if(isFull(&stk))
    {
        printf("We have successfully filled the stack\n");
    }
    else
    {
        printf("*Sad Trombone!\n");
    }

    //pop 2 things
    //push 1 thing
    // check peek that the one thing pushed is the one at the top.

    return 0;
}