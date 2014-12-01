#ifndef MAIN_H_
#define MAIN_H_

/*
 * This program is intended to be a simple calculator, with addition and
 * multiplication facilities for positive integers of infinite size. It was
 * written to showcase an ability to work with linked-list data structures,
 * and also an attempt to write solutions as elegantly as possible.
 *
 * Created by Murray Christopherson 2009. Last Updated April 2010.
 */

#include "large_integer.h"

/**
 * Though the implementation is theorectically infinite in its ability,
 * there is the small matter of taking a string in a converting it. The
 * string size must be finite. Below is the maximum number of characters
 * accepted in a string. This may be changed as needed.
 */
#define MAX_LIST_SIZE 512

/*
 * All functions below correspond to the menu shown in main()
 */

void setFirstNumber(NUMBER *list);

void setSecondNumber(NUMBER *list);

void addNumbers(NUMBER *n1, NUMBER *n2);

void multiplyNumbers(NUMBER *n1, NUMBER *n2);

void quit(int *working);

#endif
