#include <stddef.h>
#include <stdlib.h>
#include "../include/double_linked_list.h"

void insertFirst(LIST_HEAD *list, NODE *newNode) {
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
        ++(list->size);
    } else {
        insertBefore(list, list->head, newNode);
    }
}

void insertEnd(LIST_HEAD *list, NODE *newNode) {
    if (list->tail == NULL) {
        insertFirst(list, newNode);
    } else {
        insertAfter(list, list->tail, newNode);
    }
}

void insertBefore(LIST_HEAD *list, NODE *node, NODE *newNode) {
    newNode->prev = node->prev;
    newNode->next = node;
    if (node->prev == NULL) {
        list->head = newNode;
    } else {
        node->prev->next = newNode;
    }
    node->prev = newNode;
    ++(list->size);
}

void insertAfter(LIST_HEAD *list, NODE *node, NODE *newNode) {
    newNode->prev = node;
    newNode->next = node->next;
    if (node->next == NULL) {
        list->tail = newNode;
    } else {
        node->next->prev = newNode;
    }
    node->next = newNode;
    ++(list->size);
}

void removeNode(LIST_HEAD *list, NODE *n) {
    if (n->prev == NULL) {
        list->head = n->next;
    } else {
        n->prev->next = n->next;
    }
    if (n->next == NULL) {
        list->tail = n->prev;
    } else {
        n->next->prev = n->prev;
    }
    free(n);
    --(list->size);
}

void resetList(LIST_HEAD *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

LIST_HEAD *createList(void) {
    LIST_HEAD *newList = (LIST_HEAD *) malloc(sizeof (LIST_HEAD));
    if (newList == NULL) {
        return NULL;
    }
    resetList(newList);
    return newList;
}

void emptyList(LIST_HEAD *list) {
    NODE *del = list->head;
    if (del == NULL) {
        return;
    }
    while (del->next != NULL) {
        removeNode(list, del->next);
    }
    free(del);
    resetList(list);
}

void deleteList(LIST_HEAD *list) {
    emptyList(list);
    free(list);
}
