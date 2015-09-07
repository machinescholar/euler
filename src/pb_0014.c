#include <stdio.h>
#include <time.h>
#include "pb_0014.h"

long pb_0014_alt() {
	clock_t begin, end;

	begin = clock();

	const int MAX = 1000000;
	long max_elms = 0, max_int = 0, next = 0;
	long* knw_arr = (long *) malloc(MAX * sizeof(long));
	int* col_seq = (long *) malloc(MAX * sizeof(long));
	int* knw_len = (int *) malloc(MAX * sizeof(int));

	int kcnt = 0, index = 0;

	int cnt = 0;

	for (long i = 13; i < MAX; i++) {
		cnt = 1;

		while ((next = get_collatz_seq_next(i)) != 1) {
			if ((index = is_in_knw_arr(next, knw_arr, kcnt)) != -1) {
				cnt += knw_len[index] - 1;
				break;
			} else
				cnt++;

		}

		cnt += 1;

		knw_arr[kcnt] = i;
		knw_len[kcnt++] = cnt;

		if (cnt > max_elms) {
			max_elms = cnt;
			max_int = i;
			printf("Current max_int is %d\n", max_int);
		}
		printf("%d %d\n", i, max_int);
	}

	free(knw_arr);
	free(knw_len);
	end = clock();
	printf("Execution time of pb_0014 is %f\n",
			(double) (end - begin) / CLOCKS_PER_SEC);

	return max_int;
}

long pb_0014() {
	clock_t begin, end;

	begin = clock();

	const int MAX = 1000000;
	long max_elms = 1, max_int = 1, next = 0;
	long* col_seq = (long *) malloc(MAX * sizeof(long));
	long* add_lst = (long*) malloc(MAX * sizeof(long));
	int lc = 0;

	for (int i = 0; i < MAX; i++)
		add_lst[i] = 0;

	col_seq[0] = 0;
	col_seq[1] = 1;

	for (long i = 2; i < MAX; i++) {
		next = i;
		lc = 0;

		while (next > MAX - 1 || col_seq[next] == 0) {
			if (next < MAX)
				add_lst[lc++] = next;
			else
				lc++;

			next = get_collatz_seq_next(next);
		}

		for (int i = 0; i < lc; i++)
			if (add_lst[i] != 0) {
				col_seq[add_lst[i]] = col_seq[next] + lc - i;
				add_lst[i] = 0;
			}

		if (col_seq[i] > max_elms) {
			max_elms = col_seq[i];
			max_int = i;
		}
	}

	free(col_seq);
	end = clock();
	printf("Execution time of pb_0014 is %f\n",
			(double) (end - begin) / CLOCKS_PER_SEC);
	return max_int;

}

long get_collatz_seq_next(long value) {
	if (value % 2)
		value = 3 * value + 1;
	else
		value /= 2;

	return value;
}

int is_in_knw_arr(long value, const long* ka, int len) {
	int index = -1;

	if (len > 0)
		index = bin_search(value, ka, 0, len - 1);

	return index;
}

int bin_search(long value, const long* ka, int beg, int end) {
	if (beg == end)
		if (ka[beg] == value)
			return beg;
		else
			return -1;

	int mid = (beg + end) / 2;

	if (value > ka[mid])
		beg = mid + 1;
	else
		end = mid;

	return bin_search(value, ka, beg, end);
}

