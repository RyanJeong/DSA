#include <stdio.h>

#include "node.h"
#include "linkedlist.h"

void printList(LinkedList *);

int main(void)
{
    LinkedList *pList;
    Node       node;

    pList = createLinkedList();
    if (pList != NULL) {
        printList(pList);
        putchar('\n');
        /*
         * [WARNING] printList() - The linked list is empty.
         */

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
        printList(pList);
        putchar('\n');
        /*
         * [  0] 16
         * [  1] 1
         * [  2] 8
         * [  3] 2
         * [  4] 4
         */

        removeNode(pList, 0);
        removeNode(pList, 1);
        removeNode(pList, 2);
        printList(pList);
        putchar('\n');
        /*
         * [  0] 1
         * [  1] 2
         */

        deleteLinkedList(pList);
        pList = NULL;
    }

    return 0;
}

void printList(LinkedList *pList)
{
    int i, count;

    if (pList != NULL) {
        if (isListEmpty(pList) == FALSE) {
            count = getListLength(pList);
            for (i = 0; i < count; i++) {
                printf("[%3d] %d\n", i, getNode(pList, i)->data);
            }
        } else {
            printf("[WARNING] printList() - The linked list is empty.\n");
        }
    } 

    return;
}
