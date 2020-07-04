#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arraylist.h"

ArrayList *createArrayList(int size)
{
    ArrayList *ptrArrayList;

    ptrArrayList = NULL;
    if (size > 0) {
        ptrArrayList = (ArrayList *) malloc(sizeof(ArrayList));
        if (ptrArrayList != NULL) {
            ptrArrayList->maxNodeCount     = size;
            ptrArrayList->currentNodeCount = 0;
            ptrArrayList->ptrNode          = (ArrayListNode *) malloc(sizeof(ArrayListNode) * size);
            if (ptrArrayList->ptrNode != NULL) {
                memset(ptrArrayList->ptrNode, 0, sizeof(ArrayListNode) * size);
            } else {
                printf("[ERROR] Memory allocation failed.\n");
                free(ptrArrayList);
                ptrArrayList = NULL;
            }
        } else {    /* malloc returns NULL if there is insufficient memory available */
            printf("[ERROR] Memory allocation failed.\n");
        }
    } else {
        printf("[ERROR] Maximum number of nodes must be greater than 0.\n");
    }

    return ptrArrayList;
}

void deleteArrayList(ArrayList *ptrArrayList)
{
    if (ptrArrayList != NULL) {
        free(ptrArrayList->ptrNode);
        free(ptrArrayList);
    }
    
    return;
}

int isArrayListFull(ArrayList *ptrArrayList)
{
    int result;
    
    result = FALSE;
    if (ptrArrayList != NULL) {
        if (ptrArrayList->currentNodeCount == ptrArrayList->maxNodeCount) {
            result = TRUE;
        }
    }

    return result;
}

int isArrayListEmpty(ArrayList *ptrArrayList)
{
    int result;

    result = FALSE;
    if (ptrArrayList != NULL) {
        if (ptrArrayList->currentNodeCount == 0) {
            result = TRUE;
        }
    }

    return result;
}

int addNode(ArrayList *ptrArrayList, int position, ArrayListNode node)
{
    int result, i, count;
    
    result = FAILURE;
    if (ptrArrayList != NULL) {
        count = getArrayListLength(ptrArrayList);
        if (isArrayListFull(ptrArrayList) == FALSE) {
            if (position >= 0 && position <= count) {   /* <= count */
                for (i = count-1; i >= position; i--) {
                    ptrArrayList->ptrNode[i+1] = ptrArrayList->ptrNode[i];
                }
                ptrArrayList->ptrNode[position] = node;
                ptrArrayList->currentNodeCount++;
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

int addNodeFirst(ArrayList *ptrArrayList, ArrayListNode node)
{
    
    return addNode(ptrArrayList, 0, node);
}

int addNodeLast(ArrayList *ptrArrayList, ArrayListNode node)
{

    return addNode(ptrArrayList, getArrayListLength(ptrArrayList), node);
}

int removeNode(ArrayList *ptrArrayList, int position)
{
    int result, i, count;

    result = FAILURE;
    if (ptrArrayList != NULL) {
        count = getArrayListLength(ptrArrayList);
        if (isArrayListEmpty(ptrArrayList) == FALSE) {
            if (position >= 0 && position < count) {   /* < count */
                for (i = position; i < count-1; i++) {
                    ptrArrayList->ptrNode[i] = ptrArrayList->ptrNode[i+1];
                }
                ptrArrayList->currentNodeCount--;
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

void removeAll(ArrayList *ptrArrayList)
{
    if (ptrArrayList != NULL) {
        ptrArrayList->currentNodeCount = 0;
    }

    return;
}

int getArrayListLength(ArrayList *ptrArrayList)
{
    int result;
    
    result = 0;
    if (ptrArrayList != NULL) {
        result = ptrArrayList->currentNodeCount;
    }

    return result;
}

int getArrayListCapacity(ArrayList *ptrArrayList)
{
    int result;

    result = 0;
    if (ptrArrayList != NULL) {
        result = ptrArrayList->maxNodeCount;
    }

    return result;
}

ArrayListNode *getNode(ArrayList *ptrArrayList, int position)
{
    ArrayListNode *ptrNode;
    int           count;

    ptrNode = NULL;
    if (ptrArrayList != NULL) {
        count = getArrayListLength(ptrArrayList);
        if (isArrayListEmpty(ptrArrayList) == FALSE) {
            if (position >= 0 && position < count) {   /* < count */
                ptrNode = &(ptrArrayList->ptrNode[position]);
            } else {
                printf("[ERROR] The position [%d] is out of range.\n"
                       "Specify a position between 0 and %d.\n", 
                       position, count-1);
            }
        } else {
            printf("[ERROR] The array list is empty.\n");
        }
    }

    return ptrNode;
}
