#define STACK_SIZE 256

typedef struct 
{
    int top;
    char values[STACK_SIZE];
}Stack;

//Function used to initialize the stack
void initialize(Stack *stack);

//adds a element to the top of the stack
void push(Stack *stack, char value);

//removes and returns an element from the top of the stack
char pop(Stack *stack);

//function checks if the stack is empty
int isEmpty(Stack *stack);

//function checks if the stack is full
int isFull(Stack *stack);

//function looks at the next value without removing it.
char peek(Stack *stack);


