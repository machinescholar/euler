#include <stdio.h>
#include <math.h>
#include "pb_0007.h"

bool is_prime(long num) {
	if (num == 2)
		return true;

	for (int i = 2; i <= sqrt(num); i++)
		if (!(num % i))
			return false;

	return true;
}

long pb_0007(int nth) {
	int cnt = 0;
	int num = 2;

	while (true) {
		if (is_prime(num))
			cnt++;

		if (cnt == nth)
			break;

		num++;
	}

	return num;
}
