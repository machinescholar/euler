/*
 ============================================================================
 Name        : euler.c
 Author      : Machine Scholar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "pb_0001.h"
#include "pb_0002.h"
#include "pb_0003.h"
#include "pb_0004.h"
#include "pb_0005.h"
#include "pb_0006.h"
#include "pb_0007.h"
#include "pb_0008.h"
#include "pb_0009.h"
#include "pb_0010.h"
#include "pb_0011.h"
#include "pb_0012.h"
#include "pb_0013.h"

int main(void) {
	char* tmp_str;

	printf("Problem 1 answer is %d\n",pb_0001(1000));
	printf("Problem 2 answer is %d\n",pb_0002(4000000));
	printf("Problem 3 answer is %d\n",pb_0003(600851475143));
	printf("Problem 4 answer is %d\n",pb_0004());
	printf("Problem 5 answer is %d\n",pb_0005());
	printf("Problem 6 answer is %d\n",pb_0006(100));
	printf("Problem 7 answer is %d\n",pb_0007(10001));
	printf("Problem 8 answer is %ld \n",pb_0008("/home/decreator/programs/pb_0008.txt"));
	printf("Problem 9 answer is %d\n",pb_0009());
	printf("Problem 10 answer is %ld\n",pb_0010());
	printf("Problem 11 answer is %ld\n",pb_0011());
	printf("Problem 12 answer is %ld\n",pb_0012());
	tmp_str= pb_0013();
	printf("Problem 13 answer is %s\n",tmp_str);
	free(tmp_str);
	printf("Problem 14 answer is %ld\n",pb_0014());

	return EXIT_SUCCESS;
}
