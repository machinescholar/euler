#include <stdio.h>
#include <time.h>
#include "pb_0012.h"

long pb_0012() {
	clock_t begin, end;

	begin = clock();
	const int MIN_DIV = 500;
	int n=1;
	while (get_num_of_div(get_tri_num(n++)) < MIN_DIV );

	end = clock();
	printf("Execution of pb_0012 is %f\n", (double)(end- begin)/CLOCKS_PER_SEC);

	return get_tri_num(n-1);
}

int get_num_of_div(long num) {
	const int INIT_SIZ = 1;
	const int ADD_SIZ = 1;

	int* le; //keep track of exponents of each prime divisor
	int llen = INIT_SIZ;
	int lcnt = 0;
	int cnt;
	int tot_of_divs = 1;

	le = (int*) malloc(INIT_SIZ * sizeof(int));

	cnt = 0;
	while (num % 2 == 0) {
		num = num / 2;
		cnt++;
	}

	if (cnt > 0)
		le[lcnt++] = cnt;

	for (int i = 3; i * i <= num; i += 2) {
		cnt = 0;

		while (num % i == 0) {
			num = num / i;
			cnt++;
		}

		if (cnt > 0) {
			if (lcnt + 1 > llen) {
				le = (int *) realloc(le, (llen + ADD_SIZ) * sizeof(int));
				llen = llen +ADD_SIZ;
			}

			le[lcnt++] = cnt;
		}
	}

	for (int i=0;i<lcnt;i++)
		tot_of_divs *= le[i] + 1;

	free(le);
	return tot_of_divs;
}

long get_tri_num(long n) {
	return (long) n * (n+1) / 2;
}
