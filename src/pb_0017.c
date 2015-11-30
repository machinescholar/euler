/*
 * pb_0017.c
 *
 *  Created on: Sep 7, 2015
 *      Author: decreator
 */

#include <stdio.h>
#include <time.h>
#include <math.h>
#include "pb_0017.h"

const int MAX = 1000;

long pb_0017() {
	clock_t beg, end;
	beg = clock();
	int dig_arr[MAX];
	long sum = 0;

	dig_arr[0] = 0;

	for (int i = 1; i <= MAX; i++) {
		sum += get_wrd_len(dig_arr, i);
		printf("%d %d\n", i, dig_arr[i]);
	}

	end = clock();
	printf("The execution time of pb_0017 is %f\n",
			(double) (end - beg) / CLOCKS_PER_SEC);
	return sum;
}

int get_wrd_len(int dig_arr[MAX], int value) {
	int digits = 1, frs_dig = value, rem = 0;

	char units[19][20] = { "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX",
			"SEVEN", "EIGHT", "NINE", "TEN", "ELEVEN", "TWELVE", "THIRTEEN",
			"FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN",
			"NINETEEN" };

	char tens[8][20] = { "TWENTY", "THIRTY", "FORTY", "FIFTY", "SIXTY",
			"SEVENTY", "EIGHTY", "NINETY" };
	int uni_arr[7] = { 0, 8, 7, 7, 8, 11, 11 };

	if (value < 20)
		dig_arr[value] = strlen(units[value - 1]);
	else if (value < 100)
		dig_arr[value] = strlen(tens[value / 10 - 2]) + dig_arr[value % 10];
	else {
		while (frs_dig / 10 != 0) {
			digits++;
			frs_dig = frs_dig / 10;
		}

		rem = value - frs_dig * pow(10, digits - 1);

		dig_arr[value] = dig_arr[frs_dig] + uni_arr[(digits - 1) / 3]
				+ dig_arr[rem];

		if (digits == 3) { //if in hundreds then add 3 for "and" and 7 for "hundred"
			dig_arr[value] += 7;
			if (rem != 0)
				dig_arr[value] += 3;
		}
	}

	return dig_arr[value];
}

