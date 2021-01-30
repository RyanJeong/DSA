#ifndef __NODE_H__
#define __NODE_H__

typedef struct node {
    int         data;
    struct node *next;
} Node;

/* with head pointer to node */
typedef struct {
    int  nodes;
    Node *head;
} CircularLinkedList;

#endif
