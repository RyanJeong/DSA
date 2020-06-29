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
int        isLinkedListEmpty(LinkedList *);
int        addNode(LinkedList *, int, Node);
int        removeNode(LinkedList *, int);
Node       *getLinkedListNode(LinkedList *, int);

#endif
