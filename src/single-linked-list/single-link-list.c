#include <stdlib.h>
#include <stdio.h>
#include "single-link-list.h"

/**
 * For Single link list typedef structs see single-link-list.h
 * 
 */

/**
 * Caller responsibility to deallocate 
 * Empty Constructor
 */
Node* create_new_node()
{
    struct Node *newNode=malloc(sizeof(struct Node));
    char* empty="";
    newNode ->string_data=empty;
    newNode ->next=NULL;
    return newNode;
}

/**
 * Description updates the data in a single node
 */
Node* update_node_data(Node* node, const char* string_dat)
{
    node->string_data=string_dat;
    return node;
}

/**
 * Caller responsibility to deallocate 
 * data constructor
 */
Node* create_new_node_with_data(const char* data)
{
    struct Node *newNode=malloc(sizeof(struct Node));
    if(data[0] == '\0')
    {
        newNode -> string_data="\0";
    }
    else
    {
        newNode ->string_data=data;
    }
    newNode ->next=NULL;
    return newNode;
}

/**
 * Caller responsibility to deallocate 
 */
SingleLinkedList* create_new_list()
{
    struct SingleLinkedList *list=malloc(sizeof(struct SingleLinkedList));
    struct Node *newNode=NULL;
    list-> head=newNode;
    return list;
}

/**
 * grabs the last node in the linked list 
 */
Node* get_last(SingleLinkedList *list)
{
    if(list->head ==NULL)
    {
        //empty list
        return NULL;
    }

    Node *current= list->head;
    while(current->next != NULL)
    {
        current=current->next;

    }
    return current;
}

/**
 * Inserts a node at the tail of the list
 */
SingleLinkedList* insert_at_tail(SingleLinkedList *list, Node *node)
{
    if(list->head == NULL)
    {
        list->head =node;
    }
    else
    {
        Node *last_node=get_last(list);
        last_node->next=node;
    }
    return list;
}

/**
 * Inserts a node at the head of the list
 */
SingleLinkedList* insert_at_head(SingleLinkedList *list, Node *node)
{
    
    node->next=list->head;
    list->head=node;
    return list;
}

Node* get_head(SingleLinkedList *list)
{
    Node *head_ptr=list ->head;
    return head_ptr;
}

/*
** Caller responsibility to deallocate 
*/
SLLIterator* createIterator(SingleLinkedList *list)
{
    struct SLLIterator* iter=malloc(sizeof(SLLIterator));
    Node* head_node=get_head(list);
    //keep track of previous for in place deletions
    iter ->previous= NULL;
    iter->current=head_node;
    return iter;
}

void step_iter(SLLIterator *iter)
{
    Node* current=iter -> current;
    if(current == NULL)
    {
        return;
    }
    else
    {
        Node* next=current ->next;
        iter->previous=current;
        iter->current=next;
    }
}

Node* get_current(SLLIterator *iter)
{
    Node* current=iter->current;
    return current;
}

void in_place_delete(SLLIterator *iter, SingleLinkedList *list)
{
    Node* prev=iter ->previous;
    Node* curr=get_current(iter);
    if(curr == NULL)
    {
        //empty list
        return;
    }
    else
    {
        if (prev == NULL)
        {
            //We are at the first node
       
            Node* nxt=curr->next;
            list -> head=nxt;
            if(nxt == NULL)
            {
                printf("Only Node deleting whole list");
            }

        }
        else
        {
            Node* iter_next=curr ->next;
            prev ->next=iter_next;
            
        }
    }

    //stept the iter so we are not pointing to freed memory.
    step_iter(iter);

    //free the node memory
    free(curr);
}

