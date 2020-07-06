#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arraylist.h"

ArrayList *createArrayList(int size)
{
    ArrayList *pList;

    pList = NULL;
    if (size > 0) {
        pList = (ArrayList *) malloc(sizeof(ArrayList));
        if (pList != NULL) {
            pList->maxNodes = size;
            pList->nodes    = 0;
            pList->pNode    = (ArrayListNode *) malloc(sizeof(ArrayListNode) * size);
            if (pList->pNode != NULL) {
                memset(pList->pNode, 0, sizeof(ArrayListNode) * size);
            } else {
                printf("[ERROR] Memory allocation failed.\n");
                free(pList);
                pList = NULL;
            }
        } else {    /* malloc returns NULL if there is insufficient memory available */
            printf("[ERROR] Memory allocation failed.\n");
        }
    } else {
        printf("[ERROR] Maximum number of nodes must be greater than 0.\n");
    }

    return pList;
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
    int result;
    
    if (pList != NULL && pList->nodes == pList->maxNodes) {
        result = TRUE;
    } else {
        result = FALSE;
    }

    return result;
}

int isListEmpty(ArrayList *pList)
{
    int result;

    if (pList != NULL && pList->nodes == 0) {
        result = TRUE;
    } else {
        result = FALSE;
    }

    return result;
}

int addNode(ArrayList *pList, int position, ArrayListNode node)
{
    int result, i, count;
    
    result = FAILURE;
    if (pList != NULL) {
        count = getListLength(pList);
        if (isListFull(pList) == FALSE) {
            if (position >= 0 && position <= count) {   /* <= count */
                for (i = count-1; i >= position; i--) {
                    pList->pNode[i+1] = pList->pNode[i];
                }
                pList->pNode[position] = node;
                pList->nodes++;
                result = SUCCESS;
            } else {
                printf("[ERROR] The position [%d] is out of range.\n"
                       "Specify a position between 0 and %d.\n", 
                       position, count);
            }
        } else {
            printf("[ERROR] The array list is full.\n");
        }
    }

    return result;
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
    int result, i, count;

    result = FAILURE;
    if (pList != NULL) {
        count = getListLength(pList);
        if (isListEmpty(pList) == FALSE) {
            if (position >= 0 && position < count) {   /* < count */
                for (i = position; i < count-1; i++) {
                    pList->pNode[i] = pList->pNode[i+1];
                }
                pList->nodes--;
                result = SUCCESS;
            } else {
                printf("[ERROR] The position [%d] is out of range.\n"
                       "Specify a position between 0 and %d.\n", 
                       position, count-1);
            }
        } else {
            printf("[ERROR] The array list is empty.\n");
        }
    }
    
    return result;
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
    int result;
    
    if (pList != NULL) {
        result = pList->nodes;
    } else {
        result = 0;
    }

    return result;
}

int getListCapacity(ArrayList *pList)
{
    int result;

    if (pList != NULL) {
        result = pList->maxNodes;
    } else {
        result = 0;
    }

    return result;
}

ArrayListNode *getNode(ArrayList *pList, int position)
{
    ArrayListNode *pNode;
    int           count;

    pNode = NULL;
    if (pList != NULL) {
        count = getListLength(pList);
        if (isListEmpty(pList) == FALSE) {
            if (position >= 0 && position < count) {   /* < count */
                pNode = &(pList->pNode[position]);
            } else {
                printf("[ERROR] The position [%d] is out of range.\n"
                       "Specify a position between 0 and %d.\n", 
                       position, count-1);
            }
        } else {
            printf("[ERROR] The array list is empty.\n");
        }
    }

    return pNode;
}
