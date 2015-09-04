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


int main(void) {
	printf("Problem 1 answer is %d\n",pb_0001(1000));
	printf("Problem 2 answer is %d\n",pb_0002(4000000));
	printf("Problem 3 answer is %d\n",pb_0003(600851475143));
	printf("Problem 4 answer is %d\n",pb_0004());
	printf("Problem 5 answer is %d\n",pb_0005());
	printf("Problem 6 answer is %d\n",pb_0006(100));
	printf("Problem 7 asnwer is %d\n",pb_0007(10001));
	return EXIT_SUCCESS;
}
