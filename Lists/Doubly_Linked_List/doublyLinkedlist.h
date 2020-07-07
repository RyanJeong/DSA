#ifndef __DOUBLYLINKEDLIST_H__
#define __DOUBLYLINKEDLIST_H__

#include "node.h"

enum {
    FALSE,
    TRUE,

    SUCCESS = 0,
    FAILURE
};

DoublyLinkedList *createDoublyLinkedList(void);
void       deleteDoublyLinkedList(DoublyLinkedList *);
int        isListEmpty(DoublyLinkedList *);
int        addNode(DoublyLinkedList *, int, Node);
int        removeNode(DoublyLinkedList *, int);
int        getListLength(DoublyLinkedList *);
Node       *getNode(DoublyLinkedList *, int);

#endif
