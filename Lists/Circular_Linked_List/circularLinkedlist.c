#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "circularLinkedlist.h"

CircularLinkedList *createCircularLinkedList(void)
{
    CircularLinkedList *ptrCircularLinkedList;

    ptrCircularLinkedList = NULL;
    ptrCircularLinkedList = (CircularLinkedList *) malloc(sizeof(CircularLinkedList));
    if (ptrCircularLinkedList != NULL) {
        memset(ptrCircularLinkedList, 0, sizeof(CircularLinkedList));

        return ptrCircularLinkedList;
    } else {
        printf("[ERROR] createCircularLinkedList() - Memory allocation failed.\n");
        
        exit(1);
    }
}

void deleteCircularLinkedList(CircularLinkedList *ptrCircularLinkedList)
{
    int count;
    
    if (ptrCircularLinkedList != NULL) {
        count = ptrCircularLinkedList->currentNodeCount;
        while (count--) {
            /*
            printf("%d, remove %d\n", count, getCircularLinkedListNode(ptrCircularLinkedList, 0)->data);
            */
            removeNode(ptrCircularLinkedList, 0);
        }
        free(ptrCircularLinkedList);
    }

    return;
}

int isCircularLinkedListEmpty(CircularLinkedList *ptrCircularLinkedList)
{
    int result;

    result = FALSE;
    if (ptrCircularLinkedList != NULL) {
        if (ptrCircularLinkedList->currentNodeCount == 0) {
            result = TRUE;
        }
    }

    return result;
}

int addNode(CircularLinkedList *ptrCircularLinkedList, int position, Node node)
{
    int  result, i, count;
    Node *prev, *newNode, *tail;

    result = FAILURE;
    prev = newNode = tail = NULL;
    if (ptrCircularLinkedList != NULL) {
        count = ptrCircularLinkedList->currentNodeCount;
        if (position >= 0 && position <= count) {   /* <= count */
            newNode = (Node *) malloc(sizeof(Node));
            if (newNode != NULL) {
                *newNode = node;
                newNode->link = NULL;
                if (position == 0) {
                    /* case 1 */
                    if (ptrCircularLinkedList->currentNodeCount == 0) {
                        ptrCircularLinkedList->head = newNode;
                        newNode->link = newNode;
                    } else {
                        tail = ptrCircularLinkedList->head;
                        while (tail->link != ptrCircularLinkedList->head) {
                            tail = tail->link;
                        }
                    }
                } else {

                }
                prev = &(ptrCircularLinkedList->head);
                for (i = 0; i < position; i++) {
                    prev = prev->link;
                }
                newNode->link = prev->link;
                prev->link = newNode;
                ptrCircularLinkedList->currentNodeCount++;
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

int removeNode(CircularLinkedList *ptrCircularLinkedList, int position)
{
    int  result, i, count;
    Node *prev, *delNode;

    result = FAILURE;
    prev = delNode = NULL;
    if (ptrCircularLinkedList != NULL) {
        if (isCircularLinkedListEmpty(ptrCircularLinkedList) == FALSE) {
            count = ptrCircularLinkedList->currentNodeCount;
            if (position >= 0 && position < count) {   /* < count */  
                prev = &(ptrCircularLinkedList->head);
                for (i = 0; i < position; i++) {
                    prev = prev->link;
                }
                delNode = prev->link;
                prev->link = delNode->link;
                free(delNode);
                ptrCircularLinkedList->currentNodeCount--;
                result = SUCCESS;
            } else {
                printf("[WARNING] removeNode() - The position [%d] is out of range.\n"
                       "Specify a position between 0 and %d.\n", 
                       position, count);
            }
        } else {
            printf("[WARNING] removeNode() - The circular linked list is empty.\n");
        }
    }

    return result;
}

Node *getCircularLinkedListNode(CircularLinkedList *ptrCircularLinkedList, int position)
{
    Node *prev, *retNode;
    int  i, count;

    prev = retNode = NULL;
    if (ptrCircularLinkedList != NULL) {
        if (isCircularLinkedListEmpty(ptrCircularLinkedList) == FALSE) {
            count = ptrCircularLinkedList->currentNodeCount;
            if (position >= 0 && position < count) {   /* < count */  
                prev = &(ptrCircularLinkedList->head);
                for (i = 0; i <= position; i++) {
                    prev = prev->link;
                }
                retNode = prev;
            }
        } else {
            printf("[WARNING] getCircularLinkedListNode() - The circular linked list is empty.\n");
        }
    }

    return retNode;
}
