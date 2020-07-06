#include <stdio.h>

#include "arraylist.h"

void printList(ArrayList *);

int main(void)
{
    ArrayList *pList;

    pList = createArrayList(6);
    if (pList != NULL) {
        ArrayListNode node;

        node.data = 1;
        addNode(pList, 0, node);
        node.data = 2;
        addNode(pList, 1, node);
        node.data = 0;
        addNodeFirst(pList, node);
        node.data = 4;
        addNodeLast(pList, node);
        printList(pList);
/*
        Output:
        Maximum number of nodes: 6
        Current number of nodes: 4
        [index:   0], 0
        [index:   1], 1
        [index:   2], 2
        [index:   3], 4
        [index:   4], EMPTY
        [index:   5], EMPTY
*/

        removeNode(pList, 1);
        printList(pList);
/*
        Maximum number of nodes: 6
        Current number of nodes: 3
        [index:   0], 0
        [index:   1], 2
        [index:   2], 4
        [index:   3], EMPTY
        [index:   4], EMPTY
        [index:   5], EMPTY
*/
        node.data = 5;
        addNodeFirst(pList, node);
        node.data = 7;
        addNodeLast(pList, node);
        node.data = 9;
        addNode(pList, 3, node);
        printList(pList);
/*
        Maximum number of nodes: 6
        Current number of nodes: 6
        [index:   0], 5
        [index:   1], 0
        [index:   2], 2
        [index:   3], 9
        [index:   4], 4
        [index:   5], 7
*/

        removeAll(pList);
        printList(pList);
/*
        Maximum number of nodes: 6
        Current number of nodes: 0
        [index:   0], EMPTY
        [index:   1], EMPTY
        [index:   2], EMPTY
        [index:   3], EMPTY
        [index:   4], EMPTY
        [index:   5], EMPTY
*/

        deleteArrayList(pList); 
    }

    return 0;
}

void printList(ArrayList *pList)
{
    int i, len, cap;

    if (pList != NULL) {
        len = getListLength(pList);
        cap = getListCapacity(pList);
        printf("Maximum number of nodes: %d\n"
               "Current number of nodes: %d\n", 
               pList->maxNodes,
               pList->nodes);
        for (i = 0; i < len; i++) {
            printf("[index: %3d], %d\n", i, getNode(pList, i)->data);
        }
        while (i < cap) {
            printf("[index: %3d], EMPTY\n", i++);
        }
    } else {
        printf("Create an array list before execute this function.\n");
    }

    return;
}
