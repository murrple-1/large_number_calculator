#ifndef DLINKED_LIST_H_
#define DLINKED_LIST_H_

/*
 * Standard Doubly Linked List Implementatation
 *
 * Created by Murray Christopherson 2009. Last Updated April 2010.
 */

/**
 * Defines what is held in the linked list
 * data structure.
 */
#ifndef LIST_DATA_TYPE
typedef int DATA;
#else
typedef LIST_DATA_TYPE DATA;
#endif

typedef struct _tagNODE {
    struct _tagNODE *next;
    struct _tagNODE *prev;
    DATA data;
} NODE;

typedef struct _tagLIST_HEAD {
    NODE *head;
    NODE *tail;
    int size;
} LIST_HEAD;

LIST_HEAD *createList(void);

void insertFirst(LIST_HEAD *list, NODE *newNode);

void insertEnd(LIST_HEAD *list, NODE *newNode);

void insertBefore(LIST_HEAD *list, NODE *node, NODE *newNode);

void insertAfter(LIST_HEAD *list, NODE *node, NODE *newNode);

void removeNode(LIST_HEAD *list, NODE *n);

void emptyList(LIST_HEAD *list);

void deleteList(LIST_HEAD *list);

void resetList(LIST_HEAD *list);

#endif
