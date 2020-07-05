#ifndef __NODE_H__
#define __NODE_H__

typedef struct node {
    int         data;
    struct node *link;
} Node;

/* with head pointer to node */
typedef struct {
    int  currentNodeCount;
    Node *head;
} CircularLinkedList;

#endif
