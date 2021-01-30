#ifndef __CIRCULARLINKEDLIST_H__
#define __CIRCULARLINKEDLIST_H__

#include "node.h"

enum {
    FALSE,
    TRUE,

    SUCCESS = 0,
    FAILURE
};

CircularLinkedList *createCircularLinkedList(void);
void               deleteCircularLinkedList(CircularLinkedList *);
int                isListEmpty(CircularLinkedList *);
int                addNode(CircularLinkedList *, int, Node);
int                removeNode(CircularLinkedList *, int);
int                getListLength(CircularLinkedList *);
Node               *getNode(CircularLinkedList *, int);

#endif
