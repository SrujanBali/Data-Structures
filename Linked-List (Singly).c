#include <stdio.h>
#include <stdlib.h>

// Structure of the Node  {Node - A combination of VALUE and ADDRESS of the next node.}
typedef struct node
{
    int value;         // Value for the current node
    struct node *link; // Link Pointer that pointes towards the next in line node.
} Node;


//Pointer function to create new nodes. This is required to reduce code labour. Can be done manually but just don't.
Node *create_new_node(int value)
{
    Node *new_node = malloc(sizeof(Node));  //Pointer variable that allocated memory for the value and link of the node.
    new_node->value = value;   //Setting value of the new node as the value passed in the function's parameter.
    new_node->link = NULL;   //Setting the address of the node as NULL to indicate end of the linked list.

    return new_node;   //Not mandatory to return this value but is considered good practice. 
}


//Looping Function to print out the list
void printing_list(Node *first)
{
    Node *temp = first;  //Declaring temporary variable to iterate through the list and print them.
    while (temp != NULL)  //Checks and iterates through the list until the Link turns out to be NULL.
    {
        printf("%d - ", temp->value);  //Prints the value of the temporary variable.
        temp = temp->link;   //Increments the link and pushes the temporary to the next in line node.
    }
}


//Main Function
int main()
{
    Node *first = create_new_node(10);   //Pointer variable for the head of the list that contains some value
    first->link = create_new_node(20);  //Setting value for the next node from the first one.
    first->link->link = create_new_node(30);   //Setting value for the next next node from the first one.

    printing_list(first);  //Prints the Linked List.

    return 0;
}
