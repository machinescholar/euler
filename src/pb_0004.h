/*
 * pb_0004.h
 *
 *  Created on: Sep 3, 2015
 *      Author: decreator
 */

#ifndef PB_0004_H_
#define PB_0004_H_
#endif /* PB_0004_H_ */
#include <stdbool.h>

struct  int_array {
	int len;
	int* arr_ptr;
};

typedef struct int_array Int_Arr;

long pb_0004();
long reverse_num(long);
Int_Arr* create_int_array(int);
Int_Arr* resize_int_array(Int_Arr*,int);
bool is_palindrome(long);
