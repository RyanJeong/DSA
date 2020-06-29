#include <stdio.h>

#include "node.h"
#include "linkedlist.h"

void printLinkedList(LinkedList *);

int main(void)
{
    LinkedList *pLinkedList;
    Node       node;

    pLinkedList = createLinkedList();
    if (pLinkedList != NULL) {
        printLinkedList(pLinkedList);
        putchar('\n');

        node.data = 1;
        addNode(pLinkedList, 0, node);
        node.data = 2;
        addNode(pLinkedList, 1, node);
        node.data = 4;
        addNode(pLinkedList, 2, node);
        node.data = 8;
        addNode(pLinkedList, 1, node);
        node.data = 16;
        addNode(pLinkedList, 0, node);
        printLinkedList(pLinkedList);
        putchar('\n');

        removeNode(pLinkedList, 0);
        removeNode(pLinkedList, 1);
        removeNode(pLinkedList, 2);
        printLinkedList(pLinkedList);
        putchar('\n');

        deleteLinkedList(pLinkedList);
        pLinkedList = NULL;
    }

    return 0;
}

void printLinkedList(LinkedList *ptrLinkedList)
{
    int i, count;

    if (ptrLinkedList != NULL) {
        if (isLinkedListEmpty(ptrLinkedList) == FALSE) {
            count = ptrLinkedList->currentNodeCount;
            for (i = 0; i < count; i++) {
                printf("[%3d] %d\n", i, getLinkedListNode(ptrLinkedList, i)->data);
            }
        } else {
            printf("[WARNING] printLinkedList() - The linked list is empty.\n");
        }
    } 

    return;
}
