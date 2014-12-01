#ifndef LARGE_INTEGER_H_
#define LARGE_INTEGER_H_

/*
 * This can be thought of as an extension of the "linked_list" files,
 * containing all the functions that would be performed on a number.
 *
 * Created by Murray Christopherson 2009. Last Updated April 2010.
 */
#define LIST_DATA_TYPE short
#include "double_linked_list.h"

typedef DATA DIGIT;
typedef LIST_HEAD NUMBER;

/**
 * Takes a c-string, and converts it to a large number. The output is a new
 * linked list, which contains the number as specified by the input string
 * After you have finished with the number, it is recommended that you free it
 * with deleteNumber().
 * @pre 'number' is not NULL, and contains at least one character. All characters
 * 	 are numeric digits.
 * @post nothing changed
 * @return a newly created linked list, already formatted with the number input
 */
NUMBER *createNumber(char *number);
/**
 * Simple method, creates a single node, ensures it doesn't contain garbage
 * and gives it a digit, if the digit is acceptable
 * @pre 'd' should be between 0 and 9 inclusive, otherwise the nodes' digit
 *      will be 0
 * @post no change
 * @return a newly created node, with the digit assigned as appropriate
 */
NODE *createDigit(DIGIT d);
/**
 * Frees and deletes the resources created by the createNumber() method.
 * @pre 'list' is not NULL and 'list' points to an field created by 'createNumber'
 * @post 'list' will contain the same value. However, the field pointed to will
 * 	  be inaccessible
 */
void deleteNumber(NUMBER *list);
/**
 * Add two digits and a carry, putting the result and and carry-out into the
 * fields provided
 * @pre 'result' and 'carry_out' do not point to NULL or garbage. 'd1', 'd2'
 * hold only 1 digit.
 * @post 'result' will hold the one digit result, with 'carry_out' holding the
 * 	  remainder
 */
void addTwoDigits(DIGIT d1, DIGIT d2, int carry_in, DIGIT *result, int *carry_out);
/**
 * Add two full numbers, and put the result in 'result'
 * @pre all pointers do not point to NULL or garbage. 'result' does not contain any
 * 	 number yet, but has a functioning "head"
 * @post 'result' will hold the sum of 'n1' and 'n2'
 */
void addTwoNumbers(NUMBER *n1, NUMBER *n2, NUMBER *result);
/**
 * Multiply two one digit numbers, and the carry. Put the results in 'result' and
 * the carry out in 'carry_out'.
 * @pre 'result' and 'carry_out' do not point to NULL or garbage. 'd1', 'd2'
 * hold only 1 digit.
 * @post 'result' will hold the one digit result, with 'carry_out' holding the
 * 	  remainder
 */
void multiplyTwoDigits(DIGIT d1, DIGIT d2, int carry_in, DIGIT *result, int *carry_out);
/**
 * Multiply a full number by a digit, and put the result in 'result'
 * @pre all pointers do not point to NULL or garbage. 'result' does not contain any
 * 	 number yet, but has a functioning "head"
 * @post 'result' will hold the sum of 'n1' and 'digit'
 */
void multiplyNumberAndDigit(NUMBER *n1, DIGIT digit, NUMBER *result);
/**
 * A helper method for the multiplication functions. Basically, runs the function
 * num * 10Ei, (see: scientific notation) where 'num' is the 'list' and 'i' is 'power'.
 * @pre all pointers do not point to NULL or garbage
 * @post 'list' will be multiplied, as per function above
 */
void toTens(NUMBER *list, unsigned long power);
/**
 * Multiply two full numbers, and put the result in 'result'
 * @pre all pointers do not point to NULL or garbage.
 * @post 'result' will hold the sum of 'n1' and 'n2'
 */
void multiplyTwoNumbers(NUMBER *n1, NUMBER *n2, NUMBER *result);
/**
 * Output the number represented by 'list' to standard output
 * @pre 'list' is not NULL nor garbage. An empty list does nothing.
 * @post no change
 */
void printNumber(NUMBER *list);
/**
 * Sets the DIGIT at the specified node, with correction checks. If 'd' is
 * not acceptable, no change to 'n'
 * @pre 'n' is not NULL nor garbage.
 * @post if 'd' is accepted, the DIGIT at 'n' is now 'd'. Otherwise, no change
 */
void setNodeDigit(NODE *n, DIGIT d);

#endif
