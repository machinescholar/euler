#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "pb_0005.h"

long pb_0005_bruteforce() {
	const int UPPER_LIMIT = 20;

	unsigned int result = UPPER_LIMIT;
	bool skip = false;

	while (1) {
		skip = false;
		result++;

		for (int i = 2; i <= UPPER_LIMIT; i++)
			if (result % i) {
				skip = true;
				break;
			}

		if (skip)
			continue;

		if (result == UINT_MAX)
			return -1;

		return result;
	}
}

long pb_0005() {
	const int UPPER_LIMIT = 20;
	long result=2;

	for(int i=3; i <=UPPER_LIMIT;i++)
		result = lcm(result,i);


	return result;
}

int gcd(int a, int b) {
	if (!b)
		return a;

	return gcd(b, a % b);
}

long lcm(int a,int b) {
	return (long) a * b / gcd(a,b);
}
