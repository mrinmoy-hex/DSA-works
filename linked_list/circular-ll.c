#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

void traversal(struct Node *head) 
{
    if (head == NULL) return;
    
    struct Node *ptr = head;
    printf("Printing elements: ");
    do 
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("(Back to Head)\n");
}


struct Node *insertAtFirst(struct Node *head, int data) 
{
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    // Fix: Start p at head and find the last node (the node that points to head)
    struct Node *p = head;
    while (p->next != head) 
    {
        p = p->next;
    }
    
    // p is now the last node
    p->next = ptr;    // Last node points to new node
    ptr->next = head; // New node points to old head
    head = ptr;       // Update head to the new node

    return head;
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    // Fix: If index is 0, reuse insertAtFirst logic
    if (index == 0) {
        return insertAtFirst(head, data);
    }

    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    
    struct Node *p = head;
    int i = 0;

    // Traverse until the node BEFORE the target index
    while (i < index - 1)
    {
        p = p->next;
        i++;
    }
    
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    // Fix: You need to stop at the node that points to head (the current tail)
    struct Node *p = head;
    while (p->next != head) 
    {
        p = p->next;
    }

    // p is now at the last node
    p->next = ptr;    // Old last node points to new node
    ptr->next = head; // New node points back to head

    return head;
}

struct Node *deleteAtFirst(struct Node *head)
{
    if (head == NULL) return NULL;

    struct Node *ptr = head;
    struct Node *p = head;

    // We must find the last node to update its 'next' pointer
    while (p->next != head)
    {
        p = p->next;
    }

    // Now p is the last node
    head = head->next; // Move head to the second node
    p->next = head;    // Last node now points to the NEW head
    free(ptr);         // Safely free the old head

    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    if (index == 0)
    {
        return deleteAtFirst(head);
    } 
    struct Node *p = head;
    struct Node *q = head->next;
    int i = 0;

    while (i != index-1)
    {
        p = p->next;
        q = q->next;
        i++;
    }

    p->next = q->next;
    free(q);

    return head;
}

struct Node *deleteAtLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    p->next = head;
    free(q);

    return head;
}


int main() 
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));

    head->data = 4;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 8;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = head;

    printf("--- Initial Circular List ---\n");
    traversal(head);

    // 2. Testing Insertions
    printf("\n--- Testing Insertions ---\n");
    
    printf("Inserting 44 at First:\n");
    head = insertAtFirst(head, 44);
    traversal(head);

    printf("Inserting 2 at Index 2:\n");
    head = insertAtIndex(head, 2, 2);
    traversal(head);

    printf("Inserting 88 at End:\n");
    head = insertAtEnd(head, 88);
    traversal(head);

    // 3. Testing Deletions
    printf("\n--- Testing Deletions ---\n");

    printf("Deleting First Node:\n");
    head = deleteAtFirst(head);
    traversal(head);

    printf("Deleting Node at Index 2:\n");
    head = deleteAtIndex(head, 2);
    traversal(head);

    printf("Deleting Last Node:\n");
    head = deleteAtLast(head);
    traversal(head);    

    return 0;
}