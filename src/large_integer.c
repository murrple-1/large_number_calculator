#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "../include/large_integer.h"

void printNumber(NUMBER *list) {
    NODE *foll = list->head;
    while (foll != NULL) {
        printf("%d", foll->data);
        foll = foll->next;
    }
}

NUMBER *createNumber(char *number) {
    NUMBER *newList = createList();
    int i = 0;
    while (number[i] != '\0') {
        if (isdigit(number[i])) {
            NODE *n = createDigit(number[i] - '0');
            insertEnd(newList, n);
            ++i;
        }
    }
    return newList;
}

NODE *createDigit(DIGIT d) {
    NODE *newNode = (NODE *) malloc(sizeof (NODE));
    newNode->data = 0;
    newNode->next = NULL;
    newNode->prev = NULL;
    setNodeDigit(newNode, d);
    return newNode;
}

void addTwoDigits(DIGIT d1, DIGIT d2, int carry_in, DIGIT *result, int *carry_out) {
    int r = d1 + d2 + carry_in;
    int c = 0;

    while (r > 9) {
        r -= 10;
        ++c;
    }
    *result = (DIGIT) r;
    *carry_out = c;
}

void addTwoNumbers(NUMBER *n1, NUMBER *n2, NUMBER *result) {
    NUMBER *newList = createList();
    DIGIT r, d1, d2;
    int carry = 0;
    NODE *node1 = n1->tail, *node2 = n2->tail;
    while (node1 != NULL || node2 != NULL) {
        if (node1 == NULL) {
            d1 = 0;
        } else {
            d1 = node1->data;
            node1 = node1->prev;
        }
        if (node2 == NULL) {
            d2 = 0;
        } else {
            d2 = node2->data;
            node2 = node2->prev;
        }
        addTwoDigits(d1, d2, carry, &r, &carry);
        NODE *n = createDigit(r);
        insertFirst(newList, n);
    }
    while (carry > 0) {
        r = carry % 10;
        carry /= 10;
        NODE *n = createDigit(r);
        insertFirst(newList, n);
    }
    emptyList(result);
    result->head = newList->head;
    result->tail = newList->tail;
    result->size = newList->size;
    free(newList);
}

void multiplyTwoDigits(DIGIT d1, DIGIT d2, int carry_in, DIGIT *result, int *carry_out) {
    int r = (d1 * d2) + carry_in;
    int c = 0;
    while (r > 9) {
        r -= 10;
        ++c;
    }
    *result = (DIGIT) r;
    *carry_out = c;
}

void multiplyNumberAndDigit(NUMBER *n1, DIGIT digit, NUMBER *result) {
    NUMBER *newList = createList();
    DIGIT r, d;
    int carry = 0;
    NODE *node = n1->tail;
    while (node != NULL) {
        d = node->data;
        multiplyTwoDigits(d, digit, carry, &r, &carry);
        NODE *n = createDigit(r);
        insertFirst(newList, n);
        node = node->prev;
    }
    while (carry > 0) {
        r = carry % 10;
        carry /= 10;
        NODE *n = createDigit(r);
        insertFirst(newList, n);
    }
    emptyList(result);
    result->head = newList->head;
    result->tail = newList->tail;
    result->size = newList->size;
    free(newList);
}

void toTens(NUMBER *list, unsigned long power) {
    while (power > 0) {
        NODE *n = createDigit(0);
        insertEnd(list, n);
        --power;
    }
}

void multiplyTwoNumbers(NUMBER *n1, NUMBER *n2, NUMBER *result) {
    NUMBER *newList = createList(), *holder = createList();
    long i = 0L;
    NODE *node = n1->tail;
    while (node != NULL) {
        multiplyNumberAndDigit(n2, node->data, holder);
        toTens(holder, i);
        addTwoNumbers(newList, holder, newList);
        ++i;
        node = node->prev;
    }
    emptyList(result);
    result->head = newList->head;
    result->tail = newList->tail;
    result->size = newList->size;
    resetList(newList);
    deleteList(holder);
    deleteList(newList);
}

void setNodeDigit(NODE *n, DIGIT d) {
    if (d >= 0 && d <= 9) {
        n->data = d;
    }
}
