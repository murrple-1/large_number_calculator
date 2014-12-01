#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/main.h"

int main(int argc, char **argv) {
    NUMBER *firstNum = createList();
    NUMBER *secondNum = createList();
    if (firstNum == NULL || secondNum == NULL) {
        printf("Could not allocate space");
        return -1;
    }

    int select = 0;
    int working = 1;
    while (working) {
        while (select > 5 || select < 1) {
            printf("\n1.  Enter First Number\n");
            printf("2.  Enter Second Number\n");
            printf("3.  Add Numbers\n");
            printf("4.  Multiply Numbers\n");
            printf("5.  Quit\n");
            printf("Enter Selection: ");
            scanf("%d", &select);

            while (getchar() != '\n')
                continue;
        }
        switch (select) {
            case(1) :
                        setFirstNumber(firstNum);
                break;
            case(2) :
                        setSecondNumber(secondNum);
                break;
            case(3) :
                        addNumbers(firstNum, secondNum);
                break;
            case(4) :
                        multiplyNumbers(firstNum, secondNum);
                break;
            case(5) :
                        quit(&working);
                break;
            default:
                quit(&working);
        }
        select = 0;
    }
    deleteList(firstNum);
    deleteList(secondNum);
    return EXIT_SUCCESS;
}

void setFirstNumber(NUMBER *list) {
    char str[MAX_LIST_SIZE];
    printf("Input Your First Number:");
    scanf("%s", str);
    NUMBER *newList = createNumber(str);
    emptyList(list);
    list->head = newList->head;
    list->tail = newList->tail;
    list->size = newList->size;
    printf("\nSet First Number To: ");
    printNumber(list);
    free(newList);
}

void setSecondNumber(NUMBER *list) {
    char str[MAX_LIST_SIZE];
    printf("Input Your Second Number:");
    scanf("%s", str);
    NUMBER *newList = createNumber(str);
    emptyList(list);
    list->head = newList->head;
    list->tail = newList->tail;
    list->size = newList->size;
    printf("\nSet Second Number To: ");
    printNumber(list);
    free(newList);
}

void addNumbers(NUMBER *n1, NUMBER *n2) {
    if (n1->head == NULL || n2->head == NULL) {
        printf("Please Initialize The Numbers First\n");
        return;
    }
    NUMBER *tempList = createList();
    addTwoNumbers(n1, n2, tempList);
    printNumber(n1);
    printf(" + ");
    printNumber(n2);
    printf(" = ");
    printNumber(tempList);
    deleteList(tempList);
}

void multiplyNumbers(NUMBER *n1, NUMBER *n2) {
    if (n1->head == NULL || n2->head == NULL) {
        printf("Please Initialize The Numbers First\n");
        return;
    }
    NUMBER *tempList = createList();
    multiplyTwoNumbers(n1, n2, tempList);
    printNumber(n1);
    printf(" x ");
    printNumber(n2);
    printf(" = ");
    printNumber(tempList);
    deleteList(tempList);
}

void quit(int *working) {
    *working = 0;
}
