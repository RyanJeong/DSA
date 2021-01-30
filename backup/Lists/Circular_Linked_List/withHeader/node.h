#ifndef __NODE_H__
#define __NODE_H__

typedef struct node {
    int         data;
    struct node *next;
} Node;

/* with header node */
typedef struct {
    int  nodes;
    Node header;
} CircularLinkedList;

#endif
