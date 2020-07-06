#ifndef __NODE_H__
#define __NODE_H__

typedef struct node {
    int         data;
    struct node *next;
} Node;

/* with node header */
typedef struct {
    int  nodes; /* current number of nodes */
    Node header;
} LinkedList;

#endif
