#include <stdio.h>

#include "node.h"
#include "circularLinkedlist.h"

void printList(CircularLinkedList *);
void printIter(CircularLinkedList *, int);

int main(void)
{
    CircularLinkedList *pList;
    Node               node;

    pList = createCircularLinkedList();
    if (pList != NULL) {
        printList(pList);
        putchar('\n');
        printIter(pList, 11);
        putchar('\n');
        /*
         * [WARNING] printList() - The linked list is empty.
         * [WARNING] printIter() - The linked list is empty.
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
        printIter(pList, 11);
        putchar('\n');
        /*
         * [  0] 16
         * [  1] 1
         * [  2] 8
         * [  3] 2
         * [  4] 4
         *
         * [  0] 16
         * [  1] 1
         * [  2] 8
         * [  3] 2
         * [  4] 4
         * [  5] 16
         * [  6] 1
         * [  7] 8
         * [  8] 2
         * [  9] 4
         * [ 10] 16
         */

        removeNode(pList, 0);
        removeNode(pList, 1);
        removeNode(pList, 2);
        printList(pList);
        putchar('\n');
        printIter(pList, 11);
        putchar('\n');
        /*
         * [  0] 1
         * [  1] 2
         *
         * [  0] 1
         * [  1] 2
         * [  2] 1
         * [  3] 2
         * [  4] 1
         * [  5] 2
         * [  6] 1
         * [  7] 2
         * [  8] 1
         * [  9] 2
         * [ 10] 1
         */

        deleteCircularLinkedList(pList);
        pList = NULL;
    }

    return 0;
}

void printList(CircularLinkedList *pList)
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

void printIter(CircularLinkedList *pList, int iter)
{
    Node *node;
    int  i;

    if (pList != NULL) {
        if (isListEmpty(pList) == FALSE) {
            node = pList->head;
            for (i = 0; i < iter; i++) {
                printf("[%3d] %d\n", i, node->data);
                node = node->next;
            }
        } else {
            printf("[WARNING] printIter() - The linked list is empty.\n");
        }
    } 

    return;
}
