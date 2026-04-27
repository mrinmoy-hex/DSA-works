#include <stdio.h>
#include <stdlib.h>

// Node Blueprint
struct Node 
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{   
    printf("Printing array elements: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL \n");
}

struct Node *insertAtFirst(struct Node *head, int data) 
{
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;

    return ptr;
}

struct Node *insertAtBetween(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index-1) 
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    // Fix pointer linkage
    ptr->next = p->next;
    p->next = ptr;

    return head;

} 

struct Node *insertAfterNode(struct Node *prevNode, struct Node *head, int data) 
{   
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;
    
    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

struct Node *insertAtEnd(struct Node *head, int data) 
{   
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL) 
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return head;
}


int main() 
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    second->data = 4;
    second->next = third;

    third->data = 6;
    third->next = NULL;

    // Function calls
    traversal(head);

    printf("Insert At First: \n");
    head = insertAtFirst(head, 17);
    traversal(head);

    printf("Insert At Index: \n");
    head = insertAtBetween(head, 47, 2);
    traversal(head);

    printf("Insert At End: \n");
    head = insertAtEnd(head, 99);
    traversal(head);

    printf("Insert after node: \n");
    head = insertAfterNode(third, head, 55);
    traversal(head);



    return 0;
}