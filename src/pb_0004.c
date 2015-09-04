#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>
#include "pb_0004.h"

long reverse_num(long value) {
	const int INIT_SIZE = 100;
	const int RESIZE = 100;
	long result = 0;
	int digits = 0;
	Int_Arr* NumArr;

	NumArr = create_int_array(INIT_SIZE);

	while (value > 0) {
		if (digits + 1 > NumArr->len)
			resize_int_array(NumArr,RESIZE);

		NumArr->arr_ptr[digits] = value % 10;
		digits++;

		value = value / 10;
	}

	for (int i = 0; i < digits; i++) {
		result += NumArr->arr_ptr[i] * ((long) pow(10.0, digits - i - 1));
	}

	free(NumArr->arr_ptr);
	free(NumArr);

	return result;
}

long pb_0004() {
	const int UPPER_LIMIT = 999;
	const int LOWER_LIMIT = 100;
	long maxPan = 0, temp = 0;

	for (int i = LOWER_LIMIT; i <= UPPER_LIMIT; i++)
		for (int j = LOWER_LIMIT; j <= UPPER_LIMIT; j++) {
			temp = i * j;
			if (is_palindrome(temp) && temp > maxPan)
				maxPan = temp;
		}

	return maxPan;
}

Int_Arr* create_int_array(int length) {
	Int_Arr* int_arr;
	int* arr_ptr;
	arr_ptr = (int *) malloc(length * sizeof(int));

	int_arr = (Int_Arr *)malloc(sizeof(Int_Arr));
	int_arr->len = length;
	int_arr->arr_ptr = arr_ptr;

	for(int i=0; i < length;i++)
		*(int_arr->arr_ptr +i) = -1;

	return int_arr;
}

Int_Arr* resize_int_array(Int_Arr* int_arr,int inc) {
	int_arr->arr_ptr = (int *)realloc((int*)int_arr->arr_ptr, (int_arr->len + inc) * sizeof(int));
	int_arr->len += inc;

	for (int i=int_arr->len -inc; i < int_arr->len; i++)
		*(int_arr->arr_ptr + i) = -1;

	return int_arr;
}

bool is_palindrome(long value) {
	long rep_val;
	int digits = 0;
	char* str;

	rep_val = value;

	while (rep_val > 0) {
		digits++;
		rep_val = rep_val /10;
	}

	str = (char *)malloc(digits + 1);
	sprintf(str,"%d",value);

	for(int i=0, j=strlen(str)-1;i < j; i++,j--)
		if ( str[i] != str[j]) {
			free(str);
			return false;
		}

	free(str);
	return true;
}
