#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__

enum {
    FALSE, 
    TRUE,

    SUCCESS = 0,
    FAILURE
};

typedef struct {
    int data;
} ArrayListNode;

typedef struct {
    int           maxNodes;  /* Maximum number of nodes */
    int           nodes;     /* Current number of nodes */
    ArrayListNode *pNode;    /* A one-dimensional array for storing nodes */
} ArrayList;

ArrayList     *createArrayList(int);
void          deleteArrayList(ArrayList *);
int           isListFull(ArrayList *);
int           isListEmpty(ArrayList *);
int           addNode(ArrayList *, int, ArrayListNode);
int           addNodeFirst(ArrayList *, ArrayListNode);
int           addNodeLast(ArrayList *, ArrayListNode);
int           removeNode(ArrayList *, int);
void          removeAll(ArrayList *);
int           getListLength(ArrayList *);
int           getListCapacity(ArrayList *);
ArrayListNode *getNode(ArrayList *, int);

#endif
