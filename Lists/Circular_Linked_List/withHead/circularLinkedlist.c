#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "circularLinkedlist.h"

CircularLinkedList *createCircularLinkedList(void)
{
    CircularLinkedList *pList;

    pList = (CircularLinkedList *) malloc(sizeof(CircularLinkedList));
    if (pList != NULL) {
        memset(pList, 0, sizeof(CircularLinkedList));

        return pList;
    } else {
        printf("[ERROR] createCircularLinkedList() - Memory allocation failed.\n");
        
        exit(1);
    }
}

void deleteCircularLinkedList(CircularLinkedList *pList)
{
    int count;
    
    if (pList != NULL) {
        count = getListLength(pList);
        while (count--) {
            removeNode(pList, 0);
        }
        free(pList);
    }

    return;
}

int isListEmpty(CircularLinkedList *pList)
{
    if (pList != NULL && getListLength(pList) == 0) {

        return TRUE;
    } else {

        return FALSE;
    }
}

int addNode(CircularLinkedList *pList, int position, Node node)
{
    int  i, count;
    Node *prev, *newNode, *tail;

    if (pList != NULL) {
        count = getListLength(pList);
        if (position >= 0 && position <= count) {   /* <= count */
            newNode = (Node *) malloc(sizeof(Node));
            if (newNode != NULL) {
                *newNode = node;
                newNode->next = NULL;
                if (position == 0) {
                    /* case 1 */
                    if (count == 0) {
                        pList->head = newNode;
                        newNode->next = newNode;
                    /* case 2 */
                    } else {
                        tail = pList->head;
                        while (tail->next != pList->head) {
                            tail = tail->next;
                        }
                        pList->head = newNode;
                        newNode->next = tail->next;
                        tail->next = newNode;
                    }
                /* case 3 */
                } else {
                    prev = pList->head; /* point, header vs. head */
                    for (i = 0; i < position-1; i++) {
                        prev = prev->next;
                    }
                    newNode->next = prev->next;
                    prev->next = newNode;
                }
                pList->nodes++;

                return SUCCESS;
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

    return FAILURE;
}

int removeNode(CircularLinkedList *pList, int position)
{
    int  i, count;
    Node *prev, *delNode, *tail;

    if (pList != NULL) {
        if (isListEmpty(pList) == FALSE) {
            count = getListLength(pList);
            if (position >= 0 && position < count) {   /* < count */  
                if (position == 0) {
                    delNode = pList->head;
                    /* Case 1 */
                    if (count == 1) {
                        free(delNode);
                        pList->head = NULL;
                    /* Case 2 */
                    } else {
                        tail = pList->head;
                        while (tail->next != pList->head) {
                            tail = tail->next;
                        }
                        tail->next = delNode->next;
                        pList->head = delNode->next;
                        free(delNode);
                    }
                /* Case 3 */
                } else {
                    prev = pList->head;
                    for (i = 0; i < position-1; i++) {
                        prev = prev->next;
                    }
                    delNode = prev->next;
                    prev->next = delNode->next;
                    free(delNode);
                }
                pList->nodes--;

                return SUCCESS;
            } else {
                printf("[WARNING] removeNode() - The position [%d] is out of range.\n"
                       "Specify a position between 0 and %d.\n", 
                       position, count);
            }
        } else {
            printf("[WARNING] removeNode() - The circular nexted list is empty.\n");
        }
    }

    return FAILURE;
}

int getListLength(CircularLinkedList *pList)
{
    if (pList != NULL) {

        return pList->nodes;
    } else {

        return 0;
    }
}

Node *getNode(CircularLinkedList *pList, int position)
{
    Node *node;
    int  i, count;

    if (pList != NULL) {
        if (isListEmpty(pList) == FALSE) {
            count = getListLength(pList);
            if (position >= 0 && position < count) {   /* < count */  
                node = pList->head;
                for (i = 0; i < position; i++) { /* < position */
                    node = node->next;
                }

                return node;
            }
        } else {
            printf("[WARNING] getListNode() - The circular nexted list is empty.\n");
        }
    }

    return NULL;
}
