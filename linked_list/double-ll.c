#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *prev;
    struct Node *next;
};


void traversal(struct Node *ptr) 
{
    if (ptr == NULL) return;

    printf("Printing elements \n");

    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL \n");
}

void reverseTraversal(struct Node *head) 
{
    if (head == NULL) return;

    struct Node *p = head;
    // Go to last node
    while (p->next != NULL) 
    {
        p = p->next;
    }

    printf("Printing elements (Backwards): \n");

    // Walk backwards using the prev pointers
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->prev;
    }
    printf("NULL\n");
}



struct Node *insertAtFirst(struct Node *head, int data) 
{
    struct Node *p = (struct Node*) malloc(sizeof(struct Node));
    if (p == NULL) return head;

    p->data = data;
    p->next = head;
    p->prev = NULL;

    if (head != NULL) 
    {
        head->prev = p;
    }

    return p;   // New node is the head
}


struct Node *insertAtIndex(struct Node *head, int data, int index) 
{
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    if (ptr == NULL) return head;   // Check malloc error!

    ptr->data = data;

    // If index = 0 
    if (index == 0) 
    {
        return insertAtFirst(head, data);
    }

    struct Node *p = head;
    struct Node *q = head->next;
    int i = 0;

    while (i != index-1 && p != NULL)
    {
        p = p->next;
        q = q->next;
        i++;
    }

    // Index out of bound
    if (p == NULL)
    {
        free(ptr);
        return head;
    }

    ptr->next = q;
    ptr->prev = p;

    if (q != NULL)
    {
        q->prev = ptr;      // Only do this if we aren't at the very end
    }

    p->next = ptr;

    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    if (ptr == NULL) return head;   // Check malloc error!
    ptr->data = data;

    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->prev = p;
    ptr->next = NULL;

    return head;
}

struct Node *deleteFromFirst(struct Node *head) 
{
    struct Node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

struct Node *deleteFromIndex(struct Node *head, int index)
{
    if (head == NULL) return NULL;

    if (index == 0) 
    {
        return deleteFromFirst(head);
    }

    struct Node *p = head;
    int i = 0;

    // Traverse the node just before the index
    while (i != index-1 && p->next != NULL)
    {
        p = p->next;
        i++;
    }

    if (p->next == NULL)
    {
        return head;
    }

    struct Node *q = p->next;     // node to be deleted
    struct Node *res = q->next;   // node after q

    // Link p to the node after q
    p->next = res;

    // Link the node after q back to p
    if (res != NULL)
    {
        res->prev = p;
    }
    
    free(q);
    return head;
}

struct Node *deleteFromEnd(struct Node *head) 
{
    if (head == NULL) return NULL;
    if (head->next == NULL) 
    { 
        // Only one node in the list
        free(head);
        return NULL;
    }

    struct Node *p = head;
    // Move p to very last node
    while (p->next != NULL)
    {
        p = p->next;
    }

    // Move the second-to-last node's next to NULL
    p->prev->next = NULL;

    free(p);
    return head;
}


int main() 
{
    // Initialize an empty list
    struct Node *head = NULL;

    head = insertAtFirst(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);   

    printf("Initial List:\n");
    traversal(head);
    printf("----------------------------\n");

    printf("Inserting 55 at index 3:\n");
    head = insertAtIndex(head, 55, 3);
    traversal(head);
    printf("----------------------------\n");

    printf("Deleting element at index 2:\n");
    head = deleteFromIndex(head, 2);
    traversal(head);
    printf("----------------------------\n");

    printf("Trying to delete index 100 (should do nothing):\n");
    head = deleteFromIndex(head, 100);
    traversal(head);
    printf("----------------------------\n");

    reverseTraversal(head);

    return 0;
}