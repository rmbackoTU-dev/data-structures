
//A Node that makes up the list
typedef struct Node{
    const char* string_data;
    struct Node *next;
} Node;

//A list using the pointer to the head node
typedef struct SingleLinkedList{
    struct Node *head;
} SingleLinkedList;

//An iterator to the current node
typedef struct SLLIterator
{
    struct Node *current;
    struct Node *previous;
}SLLIterator;

/**
 * Caller responsibility to deallocate 
 * Empty Constructor
 */
Node* create_new_node();


/**
 * Description updates the data in a single node
 */
Node* update_node_data(Node* node, const char* string_dat);

/**
 * Caller responsibility to deallocate 
 * data constructor
 */
Node* create_new_node_with_data(const char* data);


/**
 * Caller responsibility to deallocate 
 */
SingleLinkedList* create_new_list();


/**
 * grabs the last node in the linked list 
 */
Node* get_last(SingleLinkedList *list);


/**
 * Inserts a node at the tail of the list
 */
SingleLinkedList* insert_at_tail(SingleLinkedList *list, Node *node);

/**
 * Inserts a node at the head of the list
 */
SingleLinkedList* insert_at_head(SingleLinkedList *list, Node *node);

/**
 * Description: Gets the Node pointed to by the list head
 */
Node* get_head(SingleLinkedList *list);

/*
*Description: Creates a iterator using the list. Iterator starts at list head. 
*Caller responsibility to deallocate 
*/
SLLIterator* createIterator(SingleLinkedList *list);

/*
*Description: Moves the pointer for the iterator to the next Node. 
*
*/
void step_iter(SLLIterator *iter);

/*
*Description: Returns the current node pointed to by the iterator.
*
*/
Node* get_current(SLLIterator *iter);


/*
*Description: Removes a Node pointed to by the iterator from the list
*
*/
void in_place_delete(SLLIterator *iter, SingleLinkedList *list);