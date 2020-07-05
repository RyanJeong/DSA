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
int                isCircularLinkedListEmpty(CircularLinkedList *);
int                addNode(CircularLinkedList *, int, Node);
int                removeNode(CircularLinkedList *, int);
Node               *getCircularLinkedListNode(CircularLinkedList *, int);

#endif
