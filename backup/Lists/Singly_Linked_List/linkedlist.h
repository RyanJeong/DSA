#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "node.h"

enum {
    FALSE,
    TRUE,

    SUCCESS = 0,
    FAILURE
};

LinkedList *createLinkedList(void);
void       deleteLinkedList(LinkedList *);
int        isListEmpty(LinkedList *);
int        addNode(LinkedList *, int, Node);
int        removeNode(LinkedList *, int);
int        getListLength(LinkedList *);
Node       *getNode(LinkedList *, int);

#endif
