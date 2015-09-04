#include <stdio.h>
#include "pb_0006.h"

long pb_0006_bruteforce(int max) {
	long sqr_sum =0, sum_sqr = 0;

	for (int i=1; i <= max; i++) {
		sqr_sum += i;
		sum_sqr += i * i;
	}

	sqr_sum *= sqr_sum;

	return sqr_sum - sum_sqr;

}

long pb_0006(int max) {
	long sqr_sum=0, sum_sqr=0;

	sqr_sum = max * max * (max + 1) * (max + 1)/4;
	sum_sqr = max * (max + 1) * (2*max + 1) / 6;

	return sqr_sum - sum_sqr;

}
