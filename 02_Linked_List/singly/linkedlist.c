#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "linkedlist.h"

LinkedList *createLinkedList(void)
{
    LinkedList *ptrLinkedList;

    ptrLinkedList = NULL;
    ptrLinkedList = (LinkedList *) malloc(sizeof(LinkedList));
    if (ptrLinkedList != NULL) {
        memset(ptrLinkedList, 0, sizeof(LinkedList));

        return ptrLinkedList;
    } else {
        printf("[ERROR] createLinkedList() - Memory allocation failed.\n");
        
        exit(1);
    }
}

void deleteLinkedList(LinkedList *ptrLinkedList)
{
    int count;
    
    if (ptrLinkedList != NULL) {
        count = ptrLinkedList->currentNodeCount;
        while (count--) {
            /*
            printf("%d, remove %d\n", count, getLinkedListNode(ptrLinkedList, 0)->data);
            */
            removeNode(ptrLinkedList, 0);
        }
        free(ptrLinkedList);
    }

    return;
}

int isLinkedListEmpty(LinkedList *ptrLinkedList)
{
    int result;

    result = FALSE;
    if (ptrLinkedList != NULL) {
        if (ptrLinkedList->currentNodeCount == 0) {
            result = TRUE;
        }
    }

    return result;
}

int addNode(LinkedList *ptrLinkedList, int position, Node node)
{
    int  result, i, count;
    Node *prev, *newNode;

    result = FAILURE;
    prev = newNode = NULL;
    if (ptrLinkedList != NULL) {
        count = ptrLinkedList->currentNodeCount;
        if (position >= 0 && position <= count) {   /* <= count */
            newNode = (Node *) malloc(sizeof(Node));
            if (newNode != NULL) {
                *newNode = node;
                newNode->link = NULL;
                prev = &(ptrLinkedList->header);
                for (i = 0; i < position; i++) {
                    prev = prev->link;
                }
                newNode->link = prev->link;
                prev->link = newNode;
                ptrLinkedList->currentNodeCount++;
                result = SUCCESS;
            } else {
                printf("[ERROR] addNode() - Memory allocation failed.\n");

                exit(1);
            }
        } else {
            printf("[WARNING] addNode() - The position [%d] is out of range.\n"
                   "Specify a position between 0 and %d.\n", 
                   position, count);
        }
    }

    return result;
}

int removeNode(LinkedList *ptrLinkedList, int position)
{
    int  result, i, count;
    Node *prev, *delNode;

    result = FAILURE;
    prev = delNode = NULL;
    if (ptrLinkedList != NULL) {
        if (isLinkedListEmpty(ptrLinkedList) == FALSE) {
            count = ptrLinkedList->currentNodeCount;
            if (position >= 0 && position < count) {   /* < count */  
                prev = &(ptrLinkedList->header);
                for (i = 0; i < position; i++) {
                    prev = prev->link;
                }
                delNode = prev->link;
                prev->link = delNode->link;
                free(delNode);
                ptrLinkedList->currentNodeCount--;
                result = SUCCESS;
            } else {
                printf("[WARNING] removeNode() - The position [%d] is out of range.\n"
                       "Specify a position between 0 and %d.\n", 
                       position, count);
            }
        } else {
            printf("[WARNING] removeNode() - The linked list is empty.\n");
        }
    }

    return result;
}

Node *getLinkedListNode(LinkedList *ptrLinkedList, int position)
{
    Node *prev, *retNode;
    int  i, count;

    prev = retNode = NULL;
    if (ptrLinkedList != NULL) {
        if (isLinkedListEmpty(ptrLinkedList) == FALSE) {
            count = ptrLinkedList->currentNodeCount;
            if (position >= 0 && position < count) {   /* < count */  
                prev = &(ptrLinkedList->header);
                for (i = 0; i <= position; i++) {
                    prev = prev->link;
                }
                retNode = prev;
            }
        } else {
            printf("[WARNING] getLinkedListNode() - The linked list is empty.\n");
        }
    }

    return retNode;
}
