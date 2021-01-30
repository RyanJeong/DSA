#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "doublyLinkedlist.h"

DoublyLinkedList *createDoublyLinkedList(void)
{
    DoublyLinkedList *pList;

    pList = (DoublyLinkedList *) malloc(sizeof(DoublyLinkedList));
    if (pList != NULL) {
        memset(pList, 0, sizeof(DoublyLinkedList));
        pList->header.next = &(pList->header);
        pList->header.prev = &(pList->header);

        return pList;
    } else {
        printf("[ERROR] createDoublyLinkedList() - Memory allocation failed.\n");
        
        exit(1);
    }
}

void deleteDoublyLinkedList(DoublyLinkedList *pList)
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

int isListEmpty(DoublyLinkedList *pList)
{
    if (pList != NULL && getListLength(pList) == 0) {

        return TRUE;
    } else {

        return FALSE;
    }
}

int addNode(DoublyLinkedList *pList, int position, Node node)
{
    int  i, count;
    Node *prev, *newNode;

    if (pList != NULL) {
        count = getListLength(pList);
        if (position >= 0 && position <= count) {   /* <= count */
            newNode = (Node *) malloc(sizeof(Node));
            if (newNode != NULL) {
                *newNode = node;
                prev = &(pList->header);
                for (i = 0; i < position; i++) {
                    prev = prev->next;
                }
                /* prev ] <-> [ newNode ] <-> [ ... */
                newNode->prev = prev;
                newNode->next = prev->next;
                prev->next = newNode;
                newNode->next->prev = newNode;
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

int removeNode(DoublyLinkedList *pList, int position)
{
    int  i, count;
    Node *prev, *delNode;

    if (pList != NULL) {
        if (isListEmpty(pList) == FALSE) {
            count = getListLength(pList);
            if (position >= 0 && position < count) {   /* < count */  
                prev = &(pList->header);
                for (i = 0; i < position; i++) {
                    prev = prev->next;
                }
                delNode    = prev->next;
                prev->next = delNode->next;
                delNode->next->prev = prev;
                free(delNode);
                pList->nodes--;

                return SUCCESS;
            } else {
                printf("[WARNING] removeNode() - The position [%d] is out of range.\n"
                       "Specify a position between 0 and %d.\n", 
                       position, count-1);
            }
        } else {
            printf("[WARNING] removeNode() - The linked list is empty.\n");
        }
    }

    return FAILURE;
}

int getListLength(DoublyLinkedList *pList)
{
    if (pList != NULL) {

        return pList->nodes;
    } else {

        return 0;
    }
}

Node *getNode(DoublyLinkedList *pList, int position)
{
    Node *node;
    int  i, count;

    if (pList != NULL) {
        if (isListEmpty(pList) == FALSE) {
            count = getListLength(pList);
            if (position >= 0 && position < count) {   /* < count */  
                node = pList->header.next;  /* header node is dummy node */
                for (i = 0; i < position; i++) {
                    node = node->next;
                }

                return node;
            } else {
                printf("[WARNING] getNode() - The position [%d] is out of range.\n"
                       "Specify a position between 0 and %d.\n", 
                       position, count-1);
            }
        } else {
            printf("[WARNING] getNode() - The linked list is empty.\n");
        }
    }

    return NULL;
}
