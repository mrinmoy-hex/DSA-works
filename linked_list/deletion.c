#include <stdio.h>
#include <stdlib.h>

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

// Delete first element from linked list
struct Node *deleteFirst(struct Node *head) 
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

// Delete at index from linked list
struct Node *deleteAtIndex(struct Node *head, int index) 
{
    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);

    return head;
}

// Delete last node from ll
struct Node *deleteLastNode(struct Node *head) 
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != NULL) 
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    
    return head;
}

// Delete with a given value from linked list
struct Node *deleteAtValue(struct Node *head, int value) 
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value) 
    {
        p->next = q->next;
        free(q);
    }

    return head;
}

int main() 
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));


    // Link first and second nodes
    head->data = 4;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 8;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = NULL;
    
    // Linked list before deletion
    printf("Linked list before deletion\n");
    traversal(head);

    printf("After deletion\n");

    // Function calls
    // head = deleteFirst(head);
    // head = deleteAtIndex(head, 2);
    // head = deleteLastNode(head);
    head = deleteAtValue(head, 3);
    traversal(head);




    return 0;
}