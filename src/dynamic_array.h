/*
 * dynamic_array.h
 *
 *  Created on: Sep 5, 2015
 *      Author: decreator
 */

#ifndef DYNAMIC_ARRAY_H_
#define DYNAMIC_ARRAY_H_

typedef struct int_arr {
	int len;
	int* arr_ptr;
} dyn_arr;

typedef struct int_2d_arr_ {
	int rows;
	int cols;
	int** ptr;
} int_2d_arr;

typedef struct char_2d_arr {
	int rlen;
	int clen;
	char** ptr;
} char_2d_arr;

void destroy_int_2d_arr(int_2d_arr*);
int_2d_arr* create_int_arr_or_die(int,int);
char_2d_arr* create_char_2d_arr_or_die(int,int);
//int_arr* addsiz_int_arr(int_arr*,int);
int_2d_arr* addsize_int_2d_arr_or_die(int_2d_arr*,int,int);
char_2d_arr* addsize_char_2d_arr(char_2d_arr*,int,int);
//dyn_2d_arr* create_dyn_2d_array(int,int);
//void destroy_int_arr(int_arr*);
//void destory_dyn_2d_array(dyn_2d_arr*);
void destroy_char_2d_arr(char_2d_arr*);

#endif /* DYANAMIC_ARRAY_H_ */
