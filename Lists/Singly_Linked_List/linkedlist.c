#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "linkedlist.h"

LinkedList *createLinkedList(void)
{
    LinkedList *pList;

    pList = NULL;
    pList = (LinkedList *) malloc(sizeof(LinkedList));
    if (pList != NULL) {
        memset(pList, 0, sizeof(LinkedList));

        return pList;
    } else {
        printf("[ERROR] createLinkedList() - Memory allocation failed.\n");
        
        exit(1);
    }
}

void deleteLinkedList(LinkedList *pList)
{
    int count;
    
    if (pList != NULL) {
        count = pList->nodes;
        while (count--) {
            removeNode(pList, 0);
        }
        free(pList);
    }

    return;
}

int isListEmpty(LinkedList *pList)
{
    int result;

    if (pList != NULL && pList->nodes == 0) {
        result = TRUE;
    } else {
        result = FALSE;
    }

    return result;
}

int addNode(LinkedList *pList, int position, Node node)
{
    int  result, i, count;
    Node *prev, *newNode;

    result = FAILURE;
    if (pList != NULL) {
        count = pList->nodes;
        if (position >= 0 && position <= count) {   /* <= count */
            newNode = (Node *) malloc(sizeof(Node));
            if (newNode != NULL) {
                *newNode      = node;
                newNode->next = NULL;
                prev = &(pList->header);
                for (i = 0; i < position; i++) {
                    prev = prev->next;
                }
                newNode->next = prev->next;
                prev->next    = newNode;
                pList->nodes++;
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

int removeNode(LinkedList *pList, int position)
{
    int  result, i, count;
    Node *prev, *delNode;

    result = FAILURE;
    if (pList != NULL) {
        if (isListEmpty(pList) == FALSE) {
            count = pList->nodes;
            if (position >= 0 && position < count) {   /* < count */  
                prev = &(pList->header);
                for (i = 0; i < position; i++) {
                    prev = prev->next;
                }
                delNode    = prev->next;
                prev->next = delNode->next;
                free(delNode);
                pList->nodes--;
                result = SUCCESS;
            } else {
                printf("[WARNING] removeNode() - The position [%d] is out of range.\n"
                       "Specify a position between 0 and %d.\n", 
                       position, count-1);
            }
        } else {
            printf("[WARNING] removeNode() - The linked list is empty.\n");
        }
    }

    return result;
}

Node *getNode(LinkedList *pList, int position)
{
    Node *prev, *node;
    int  i, count;

    if (pList != NULL) {
        if (isListEmpty(pList) == FALSE) {
            count = pList->nodes;
            if (position >= 0 && position < count) {   /* < count */  
                prev = &(pList->header);
                for (i = 0; i <= position; i++) {
                    prev = prev->next;
                }
                node = prev;
            } else {
                printf("[WARNING] getNode() - The position [%d] is out of range.\n"
                       "Specify a position between 0 and %d.\n", 
                       position, count-1);
            }
        } else {
            printf("[WARNING] getNode() - The linked list is empty.\n");
        }
    }

    return node;
}
