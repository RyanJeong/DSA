#include <stdio.h>

#include "node.h"
#include "linkedlist.h"

void printLinkedList(LinkedList *);

int main(void)
{
    LinkedList *pList;
    Node       node;

    pList = createLinkedList();
    if (pList != NULL) {
        printLinkedList(pList);
        putchar('\n');

        node.data = 1;
        addNode(pList, 0, node);
        node.data = 2;
        addNode(pList, 1, node);
        node.data = 4;
        addNode(pList, 2, node);
        node.data = 8;
        addNode(pList, 1, node);
        node.data = 16;
        addNode(pList, 0, node);
        printLinkedList(pList);
        putchar('\n');

        removeNode(pList, 0);
        removeNode(pList, 1);
        removeNode(pList, 2);
        printLinkedList(pList);
        putchar('\n');

        deleteLinkedList(pList);
        pList = NULL;
    }

    return 0;
}

void printLinkedList(LinkedList *pList)
{
    int i, count;

    if (pList != NULL) {
        if (isListEmpty(pList) == FALSE) {
            count = pList->nodes;
            for (i = 0; i < count; i++) {
                printf("[%3d] %d\n", i, getNode(pList, i)->data);
            }
        } else {
            printf("[WARNING] printLinkedList() - The linked list is empty.\n");
        }
    } 

    return;
}
