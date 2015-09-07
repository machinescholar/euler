#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pb_0013.h"

bool read_from_file_or_die(const char* filepath, char_2d_arr* in_arr) {
	FILE* fp;
	size_t byte_read, line_len;
	char* line_read = NULL;
	int ncnt = 0;

	fp = fopen(filepath, "r");
	if (fp == NULL) {
		fprintf(stderr, "Can not open %s...", filepath);
		exit(EXIT_FAILURE);
	}

	while ((byte_read = getline(&line_read, &line_len, fp)) != -1) {
		line_read[byte_read - 1] = '\0';

		if (ncnt + 1 > in_arr->rlen)
			addsize_char_2d_arr(in_arr, ncnt + 1 - in_arr->rlen, 0);

		if (byte_read > in_arr->clen) {
			addsize_char_2d_arr(in_arr, 0, byte_read - in_arr->clen);

			for (int i = 0; i < in_arr->rlen; i++)
				in_arr->ptr[in_arr->clen - 1] = '\0';
		}

		for (int i = 0; i < byte_read - 1; i++)
			in_arr->ptr[ncnt][i] = line_read[i];

		in_arr->ptr[ncnt][byte_read - 1] = '\0';

		ncnt++;
	}

	fclose(fp);
	if (line_read)
		free(line_read);

	return true;
}

char* pb_0013() {
	clock_t begin, end;
	begin = clock();

	const int INIT_ROWS = 1;
	const int INIT_COLS = 1;
	const int MAX_LEN = 1000;
	const int DIGITS_LEN = 10;

	const char* filepath = "/home/decreator/programs/pb_0013.txt";
	char_2d_arr* in_arr = create_char_2d_arr_or_die(INIT_ROWS, INIT_COLS);
	char output[MAX_LEN];
	char* result = (char*) malloc((DIGITS_LEN + 1) * sizeof(char));
	int k = 0, rem = 0;

	read_from_file_or_die(filepath, in_arr);

	for (int j = in_arr->clen - 2; j >= 0; j--) {
		int sum = 0;

		for (int i = 0; i < in_arr->rlen; i++)
			sum += in_arr->ptr[i][j] - '0';

		sum += rem;
		output[k++] = sum % 10 + '0';
		rem = sum / 10;
	}

	while (rem != 0) {
		output[k++] = rem % 10 + '0';
		rem = rem / 10;
	}

	for (int i = k - 1, j = 0; i > k - DIGITS_LEN - 1; i--, j++)
		result[j] = output[i];

	result[DIGITS_LEN] = '\0';

	destroy_char_2d_arr(in_arr);
	end = clock();
	printf("The execution of pb_0013 is %f\n",
			(double) (end - begin) / CLOCKS_PER_SEC);

	return result;
}
