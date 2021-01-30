#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arraylist.h"

ArrayList *createArrayList(int size)
{
    ArrayList *pList;

    if (size > 0) {
        pList = (ArrayList *) malloc(sizeof(ArrayList));
        if (pList != NULL) {
            pList->maxNodes = size;
            pList->nodes    = 0;
            pList->pNode    = (ArrayListNode *) malloc(sizeof(ArrayListNode) * size);
            if (pList->pNode != NULL) {
                memset(pList->pNode, 0, sizeof(ArrayListNode) * size);

                return pList;
            } else {
                printf("[ERROR] CreateArrayList() - Memory allocation failed.\n");
                free(pList);

                exit(1);
            }
        } else {    /* malloc returns NULL if there is insufficient memory available */
            printf("[ERROR] CreateArrayList() - Memory allocation failed.\n");

            exit(1);
        }
    } else {
        printf("[WARNING] CreateArrayList() - Maximum number of nodes must be greater than 0.\n");

        return NULL;
    }
}

void deleteArrayList(ArrayList *pList)
{
    if (pList != NULL) {
        free(pList->pNode);
        free(pList);
    }
    
    return;
}

int isListFull(ArrayList *pList)
{
    if (pList != NULL && pList->nodes == pList->maxNodes) {

        return TRUE;
    } else {

        return FALSE;
    }
}

int isListEmpty(ArrayList *pList)
{
    if (pList != NULL && pList->nodes == 0) {

        return TRUE;
    } else {

        return FALSE;
    }
}

int addNode(ArrayList *pList, int position, ArrayListNode node)
{
    int i, count;
    
    if (pList != NULL) {
        count = getListLength(pList);
        if (isListFull(pList) == FALSE) {
            if (position >= 0 && position <= count) {   /* <= count */
                for (i = count-1; i >= position; i--) {
                    pList->pNode[i+1] = pList->pNode[i];
                }
                pList->pNode[position] = node;
                pList->nodes++;

                return SUCCESS;
            } else {
                printf("[WARNING] addNode() - The position [%d] is out of range.\n"
                       "Specify a position between 0 and %d.\n", 
                       position, count);
            }
        } else {
            printf("[WARNING] addNode() - The array list is full.\n");
        }
    }

    return FAILURE;
}

int addNodeFirst(ArrayList *pList, ArrayListNode node)
{
    
    return addNode(pList, 0, node);
}

int addNodeLast(ArrayList *pList, ArrayListNode node)
{

    return addNode(pList, getListLength(pList), node);
}

int removeNode(ArrayList *pList, int position)
{
    int i, count;

    if (pList != NULL) {
        count = getListLength(pList);
        if (isListEmpty(pList) == FALSE) {
            if (position >= 0 && position < count) {   /* < count */
                for (i = position; i < count-1; i++) {
                    pList->pNode[i] = pList->pNode[i+1];
                }
                pList->nodes--;

                return SUCCESS;
            } else {
                printf("[WARNING] removeNode() - The position [%d] is out of range.\n"
                       "Specify a position between 0 and %d.\n", 
                       position, count-1);
            }
        } else {
            printf("[WARNING] removeNode() - The array list is empty.\n");
        }
    }
    
    return FAILURE;
}

void removeAll(ArrayList *pList)
{
    if (pList != NULL) {
        pList->nodes = 0;
    }

    return;
}

int getListLength(ArrayList *pList)
{
    if (pList != NULL) {
        
        return pList->nodes;
    } else {

        return 0;
    }
}

int getListCapacity(ArrayList *pList)
{
    if (pList != NULL) {

        return pList->maxNodes;
    } else {

        return 0;
    }
}

ArrayListNode *getNode(ArrayList *pList, int position)
{
    int count;

    if (pList != NULL) {
        count = getListLength(pList);
        if (isListEmpty(pList) == FALSE) {
            if (position >= 0 && position < count) {   /* < count */

                return &(pList->pNode[position]);
            } else {
                printf("[WARNING] getNode() - The position [%d] is out of range.\n"
                       "Specify a position between 0 and %d.\n", 
                       position, count-1);
            }
        } else {
            printf("[WARNING] getNode() - The array list is empty.\n");
        }
    }

    return NULL;
}
