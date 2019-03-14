/*
* I really want to understand the linked list. So I wrote this program on the source below. 
*
* source: http://www.zentut.com/c-tutorial/c-linked-list/
* I will write another one next times.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node
{
    int value;
    struct node *next;
} node;

typedef void (* callback)(node *data);

node *create(int data, node *next)
{
    node *new_node = (node *) malloc(sizeof(node));
    if(!new_node)
    {
        printf("[ERROR] creating a new node\n");
        return NULL;
    }
    new_node->value = data;
    new_node->next = next;
    return new_node;

}

node *preend(node *head, int data)
{
    node *new_node = create(data, head);
    head = new_node;
    return head;
}

node *append(node *head, int data)
{
    if(!head)
    {
        return NULL;
    }

    /* go to the last node */
    node *cursor = head;
    while(cursor->next != NULL)
    {
        cursor = cursor->next;
    }

    /* create a new node */
    node *new_node = create(data, NULL);
    cursor->next = new_node;

    return head;
}

node *insert_after(node *head, int data, node *prev)
{
    if((!head) || (!prev))
    {
        return NULL;
    }

    /* find the prev node, starting from the first node */
    node *cursor = head;
    while(cursor != prev)
    {
        cursor = cursor->next;
    }
    if(cursor != NULL)
    {
        node * new_node = create(data, cursor->next);
        cursor->next = new_node;
        return head;
    }
    else
    {
        return NULL;
    }
}

node *insert_before(node *head, int data, node *nxt)
{
    if((!nxt) || (!head))
    {
        return NULL;
    }

    if(head == nxt)
    {
        head = prepend(head, data);
        return head;
    }

    /* find the previous node, starting from the first node */
    node *cursor = head;
    while(cursor)
    {
        if(cursor->next == nxt)
        {
            break;
        }
        cursor = cursor->next;
    }
    
    if(cursor)
    {
        node *new_node = create(data, cursor->next);
        cursor->next = new_node;
        return head;
    }
    else
    {
        return NULL;
    }
}

void traverse(node *head, callback function)
{
    node *cursor = head;
    while(cursor != NULL)
    {
        function(cursor);
        cursor = cursor->next;
    }
}

node *remove_front(node *head)
{
    if(head == NULL)
    {
        return NULL;
    }

    node *front = head;
    head = head->next;
    front->next = NULL;

    /* is this the last node in the list */
    if(front == head)
    {
        head = NULL;
    }
    free(front);
    return head;
}

node *remove_back(node *head)
{
    if(!head)
    {
        return NULL;
    }

    node *cursor = head;
    node *back = NULL;
    while(cursor->next != NULL)
    {
        back = cursor;
        cursor = cursor->next;    
    }
    if(back != NULL)
    {
        back->next = NULL;
    }

    /* if this is the last node in the list */
    if(cursor == head)
    {
        head = NULL;
    }
    free(cursor);

    return head;
}

node *remove_any(node *head, node *nd)
{
    /* if the node is the first node */
    if(nd == head)
    {
        head = remove_front(head);
        return head;
    }

   /* if the node is the last node */
    if(nd->next == NULL)
    {
        head = remove_back(head);
        return head;
    }

    /* if the node is in the middle */
    node *cursor = head;
    while(cursor != NULL)
    {
        if(cursor->next == nd)
        {
            break;
        }
        cursor = cursor->next;
    }
    
    if(cursor != NULL)
    {
        node *tmp = cursor->next;
        cursor->next = tmp->next;
        tmp->next = NULL;
    }
    return head;
}

void dispose(node *head)
{
    node *cursor, *tmp;
    if(head != NULL)
    {
        cursor = head->next;
        head->next = NULL;
        while(cursor != NULL)
        {
            tmp = cursor->next;
            free(cursor);
            cursor = tmp;
        }
    }
}

int main(int argc, char **argv)
{
    /* TODO */
    return 0;
}