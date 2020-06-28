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
int        addElement(LinkedList *, int, Node);
int        removeElement(LinkedList *, int);
void       removeAll(LinkedList *);
int        isLinkedListEmpty(LinkedList *);
int        getLinkedListLength(LinkedList *);
Node       *getLinkedListElement(LinkedList *, int);

#endif
