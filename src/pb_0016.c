#include <stdio.h>
#include <time.h>
#include "pb_0016.h"

int pb_0016() {
	clock_t beg,end;
	beg=clock();

	const int SIZE = 100;
	const int BASE = 2;
	const int EXP = 1000;
	int digits = 1, times = EXP, max_len = SIZE;
	int carry = 0;
	int sum = 0;

	unsigned short* result = (unsigned short *) malloc(
			SIZE * sizeof(unsigned short));

	for (int i = 1; i < SIZE; i++)
		result[i] = 0;

	result[0] = 1;

	while (times-- > 0) {
		for (int i = 0; i < digits; i++) {
			result[i] = BASE * result[i] + carry;

			if (result[i] > 9) {
				result[i] = result[i] % 10;
				carry = 1;

				if (i == max_len - 1) {
					result = (unsigned short *) realloc(result,
							(max_len + SIZE) * sizeof(unsigned short));

					for (int i = max_len; i < max_len + SIZE; i++)
						result[i] = 0;

					max_len += SIZE;
				}

				if (i == digits - 1)
					digits++;
			} else
				carry = 0;
		}
	}

	for (int i = 0; i < digits; i++)
		sum += result[i];
	end=clock();

	printf("The execution of pb_0016 is %f\n",(double)(end-beg)/CLOCKS_PER_SEC);
	return sum;

}

