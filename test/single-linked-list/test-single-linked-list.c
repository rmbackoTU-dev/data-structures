#include <stdio.h>
#include <string.h>
#include "..\..\src\single-linked-list\single-link-list.h"

int test_create_empty_node()
{
    Node* empty_node=create_new_node();
    int result=0;
    const char* data= empty_node -> string_data; 
    result= ( data[0] == '\0') ? 1 : 0; 
    return result;
}

int test_create_populated_node()
{
    Node* node=create_new_node_with_data("Hello world");
    int result=0;
    const char* data= node -> string_data; 
    result= ( data[0] != '\0' && data[0] == 'H') ? 1 : 0; 
    return result;
}


int test_create_null_populated_node()
{
    Node* node=create_new_node_with_data("\0");
    int result=0;
    const char* data= node -> string_data; 
    result= ( data[0] == '\0') ? 1 : 0; 
    return result;
}

int test_create_empty_str_populated_node()
{
    Node* node=create_new_node_with_data("");
    int result=0;
    const char* data= node -> string_data; 
    result= ( data[0] == '\0') ? 1 : 0; 
    return result;
}

int test_insert_new_node_into_list()
{
    int result=0;
    Node* node=create_new_node_with_data("Hello world");
    SingleLinkedList* new_list=create_new_list();
    insert_at_head(new_list, node);
    Node* head_node=get_head(new_list);
    const char* data=head_node -> string_data;
    /*string compare returns zero if strings match 
    *< 0 if Left operand comes before the right operand alphabetically
    *> 0 if Left operand comes after the right operand alphabetically
    * - So a zero result would need to be converted to a 1 result to get expected compairson result
    */
    int string_result=strcmp("Hello world", data);
    result=(string_result == 0) ? 1 : 0;
    return result;
}

int test_insert_at_end_one_node()
{
     int result=0;
    Node* node_one=create_new_node_with_data("Hello world");
    Node* node_two=create_new_node_with_data("Hello again!");
    SingleLinkedList* new_list=create_new_list();
    insert_at_head(new_list, node_one);
    insert_at_tail(new_list, node_two);
    Node* head_node=get_head(new_list);
    Node* tail_node=get_last(new_list);
    const char* head_data=head_node -> string_data;
    const char* tail_data=tail_node -> string_data;
    /*string compare returns zero if strings match 
    *< 0 if Left operand comes before the right operand alphabetically
    *> 0 if Left operand comes after the right operand alphabetically
    * - So a zero result would need to be converted to a 1 result to get expected compairson result
    */
    int string_compare_head=strcmp("Hello world", head_data);
    int string_compare_tail=strcmp("Hello again!", tail_data);
    //We need the head and tail to match to guarantee the results of the inserts were deterministic.
    result=((string_compare_head == 0) && (string_compare_tail == 0))? 1: 0;
    return result;
}

int test_insert_at_start_one_node()
{
     int result=0;
    Node* node_one=create_new_node_with_data("Hello world");
    Node* node_two=create_new_node_with_data("Hello again!");
    SingleLinkedList* new_list=create_new_list();
    insert_at_head(new_list, node_one);
    insert_at_head(new_list, node_two);
    Node* head_node=get_head(new_list);
    Node* tail_node=get_last(new_list);
    const char* head_data=head_node -> string_data;
    const char* tail_data=tail_node -> string_data;
    /*string compare returns zero if strings match 
    *< 0 if Left operand comes before the right operand alphabetically
    *> 0 if Left operand comes after the right operand alphabetically
    * - So a zero result would need to be converted to a 1 result to get expected compairson result
    */
    int string_compare_head=strcmp("Hello again!", head_data);
    int string_compare_tail=strcmp("Hello world", tail_data);
    //We need the head and tail to match to guarantee the results of the inserts were deterministic.
    result=((string_compare_head == 0) && (string_compare_tail == 0))? 1: 0;
    return result;
}

int test_iterate_two_node_list()
{
    int result=0;
    Node* node_one=create_new_node_with_data("Hello world");
    Node* node_two=create_new_node_with_data("Hello again!");
    SingleLinkedList* new_list=create_new_list();
    insert_at_head(new_list, node_one);
    insert_at_head(new_list, node_two);
    const char *expected[]={
        "Hello again!",
        "Hello world"
    };
    SLLIterator* ittr = createIterator(new_list);
    int i=0;
    int diff_status=1;
    //Exit the while loop if we reach the end or one of the strings differs
    const char* cmpr_val;
    const char* curr_iter_val=(ittr->current) -> string_data;
    const char* status[]={"Success", "Failed"};
    printf("Size of results %d\n", sizeof(expected));
    //DEBUG: lWhy is the above 16
    while((i< sizeof(expected)) && (diff_status != 0))
    {
        cmpr_val=expected[i];
        int string_rlst=strcmp(cmpr_val, curr_iter_val);
        diff_status=(string_rlst == 0) ?  1 : 0;
        const char* curr_stat=(diff_status == 1 )? status [0] : status [1];
        printf("String compairson of %s to %s had result %s\n", curr_iter_val, cmpr_val, curr_stat);
        step_iter(ittr);
        i++;
        //TODO: DEBUG here. loop should exit i > sizeof expected 2
        printf("Iterator num %d\n", i);
        curr_iter_val=(ittr->current) -> string_data;
    }
    result= (diff_status == 1 ) ? 1: 0;
    return result;
}

int test_iterate_three_node_list()
{
    return 0;
}

int test_iterate_four_node_list()
{
    return 0;
}

int test_delete_first_4_node_list()
{
    return 0;
}


int test_delete_last_4_node_list()
{
    return 0;
}

int test_delete_second_4_node_list()
{
    return 0;
}

int test_retrieve_first_4_node_list()
{
    return 0;
}

int test_retrieve_last_4_node_list()
{
    return 0;
}

int test_retrieve_second_4_node_list()
{
    return 0;
}



int main()
{
    

    /*
    * Requirements:
    *   1. User shall be able to create a empty list.
    *   2. User shall be able to create a empty Node.
    *   3. User shall be able to update string data in a Node.
    *   4. User shall be able to create a node with string data preloaded.
    *   5. User shall be able to insert a Node into the empty list
    *   6. User shall be able to insert a Node into a list with one element at the end 
    *   7. User shall be able to insert a Node into a list with one element at the beginning
    *   8. When a User attempts to iterate on the last element of a list the list shall give an error
    *   9. Users shall be able to iterat through a list with 2 elements.
    *   10. User shall be able to iterate through a list with 3 elements.
    *   11. User shall be able to iterate through a list with 4 elements
    *   12. User Shall be able to delete the 1st Node in a 4 element list
    *   13. User shall be able to delete the last Node in a 4 element list
    *  14. User shall be able to delete the 2nd Node in a 4 element list.
    *  15. User shall be able to retrieve the first Node of the list
    *  16. Use shall be able to retrieve the last Node of the list.
    *  17. Use shall be able to retrieve the second Node of the list (4 nodess).
    * 
    */

    //test 2:
    int result_two=test_create_empty_node();
    //test 3:
    int result_three=test_create_populated_node();
    //test 4:
    int result_four=test_create_null_populated_node();
    //test 5:
    int result_five=test_create_empty_str_populated_node();
    //test 6:
    int result_six=test_insert_new_node_into_list();
    //test 7:
    int result_seven=test_insert_at_end_one_node();
    //test 8:
    int result_eight=test_insert_at_start_one_node();
    //test 9:
    int result_nine=test_iterate_two_node_list();

    if(result_two == 1)
    {
        printf("\nRequirement 2: User shall be able to create empty node successful --Test (test_create_empty_node)\n");
    }
    else
    {
        printf("\nRequirement 2: User shall be able to create empty node failed --Test (test_create_empty_node)\n");
    }
    

    if(result_three == 1)
    {
        printf("\nRequirement 4: User shall be able to create a node with string data preloaded successful --Test (test_create_populated_node)\n");
    }
    else
    {
        printf("\nRequirement 4: User shall be able to create a node with string data preloaded  failed --Test (test_create_populated_node)\n");
    }


    if(result_four == 1)
    {
        printf("\nRequirement 2: User shall be able to create empty node successful. successful --Test (test_create_null_populated_node)\n");
    }
    else
    {
        printf("\nRequirement 2: User shall be able to create empty node failed --Test (test_create_null_populated_node)\n");
    }


    if(result_five == 1)
    {
        printf("\nRequirement 2: User shall be able to create empty node successful. --Test (test_create_empty_str_populated_node)\n");
    }
    else
    {
        printf("\nRequirement 2: User shall be able to create empty node failed  --Test (test_create_empty_str_populated_node)\n");
    }


     if(result_six == 1)
    {
        printf("\nRequirement 5: User shall be able to insert a Node into the empty list successful. --Test (test_insert_new_node_into_list)\n");
    }
    else
    {
        printf("\nRequirement 5: User shall be able to insert a Node into the empty list failed  --Test (test_insert_new_node_into_list)\n");
    }


     if(result_seven == 1)
    {
        printf("\nRequirement 6: User shall be able to insert a Node into a list with one element at the end was successful. --Test (test_insert_at_end_one_node)\n");
    }
    else
    {
        printf("\nRequirement 6: User shall be able to insert a Node into a list with one element at the end failed  --Test (test_insert_at_end_one_node)\n");
    }

     if(result_eight == 1)
    {
        printf("\nRequirement 7: User shall be able to insert a Node into a list with one element at the beginning was successful. --Test (test_insert_at_start_one_node)\n");
    }
    else
    {
        printf("\nRequirement 7: User shall be able to insert a Node into a list with one element at the beginning failed  --Test (test_insert_at_start_one_node)\n");
    }

    if(result_nine == 1)
    {
        printf("\nRequirement 8: Users shall be able to iterate through a list with 2 elements was successful. --Test (test_iterate_two_node_list)\n");
    }
    else
    {
        printf("\nRequirement 8: Users shall be able to iterate through a list with 2 elements failed. --Test (test_iterate_two_node_list)\n");
    }
    

    return 0;

}
