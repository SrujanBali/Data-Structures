#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next_link;
    struct Node *prev_link;
} Node;

typedef struct List
{
    struct Node *head;
    struct Node *tail;
} List;

Node *create_node(int value)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next_link = NULL;
    new_node->prev_link = NULL;
}

void list_innit(List *list)
{
    list->head = NULL;
    list->tail = NULL;
}

void list_append(List *list, Node *node)
{
    if (node)
    {
        node->next_link = NULL;
        node->prev_link = list->tail;
        if (list->tail)
        {
            list->tail->next_link = node;
        }
        else
        {
            list->head = node;
        }
        list->tail = node;
    }
}

void free_node(Node *node)
{
    free(node);
}

Node *list_first(List *list)
{
    return list->head;
}

Node *list_last(List *list)
{
    return list->tail;
}

void forward_traversing(List *list)
{
    Node *temp = list_first(list);

    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next_link;
    }
    printf("\n");
}

void backward_traversing(List *list)
{
    Node *temp = list_last(list);

    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->prev_link;
    }
    printf("\n");
}

void list_remove_node(List *list, Node *node)
{
    if (node)
    {
        Node *next = node->next_link;
        Node *prev = node->prev_link;

        if (next)
        {
            next->prev_link = prev;
        }
        else
        {
            list->tail = prev;
        }
        if (prev)
        {
            prev->next_link = next;
        }
        else
        {
            list->head = next;
        }
        node->next_link = NULL;
        node->prev_link = NULL;
    }
}

Node *remove_first(List *list)
{
    Node *node = list_first(list);

    list_remove_node(list, node);
    return node;
}

Node *remove_last(List *list)
{
    Node *node = list_last(list);

    list_remove_node(list, node);
    return node;
}

void free_list_nodes(List *list)
{
    Node *temp;

    while ((temp = remove_first(list)) != NULL)
    {
        free_node(temp);
    }
}

void search(List *list, int x){
    Node *temp = list_first(list);
    int pos = 0;

    while(temp != NULL){
        if (temp != 0 && temp -> value != x){
            pos ++;
        }
        else if (temp != NULL && temp -> value ==x){
            printf("%d is at position %d in the list", x, pos + 1);
        }
        else{
            printf("Element not found");
        }
        temp = temp -> next_link;
    }
}

int main()
{
    Node *node;
    List list;

    list_innit(&list);

    for (int i = 0; i <= 25; i++)
    {
        node = create_node(i);

        if (node)
        {
            list_append(&list, node);
        }
    }

    forward_traversing(&list);
    backward_traversing(&list);

    search(&list, 3);

    free_list_nodes(&list);
    return 0;
}