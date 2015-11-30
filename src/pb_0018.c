#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "commath.h"
#include "pb_0018.h"

int pb_0018() {
	clock_t beg, end;
	beg = clock();
	const int INIT_SIZE = 10;
	const char* file_path = "/home/decreator/programs/pb_0018.txt";
	int_2d_arr* in_arr = create_int_2d_arr_or_die(INIT_SIZE, INIT_SIZE);
	int result = 0;

	read_from_file_or_die_0018(file_path, in_arr);



	printf("%d %d\n", in_arr->rows, in_arr->cols);
	for (int i = in_arr->rows - 2; i >= 0; i--)
		for (int j = 0; j < in_arr->cols - (in_arr->rows - i - 1); j++)
			in_arr->ptr[i][j] = in_arr->ptr[i][j]
					+ max(in_arr->ptr[i + 1][j], in_arr->ptr[i + 1][j + 1]);

	result = in_arr->ptr[0][0];
	destroy_int_2d_arr(in_arr);
	end = clock();
	printf("Execution of pb_0018 is %f\n", (end - beg) / CLOCKS_PER_SEC);
	return result;
}

void read_from_file_or_die_0018(const char* file_path, int_2d_arr* in) {
	size_t byte_read, line_len;
	int m = 0, n = 0;
	char* line_read = NULL;
	FILE* fp;

	fp = fopen(file_path, "r");
	if (fp == NULL) {
		fprintf(stderr, "Cannot open %s...", file_path);
		exit(EXIT_FAILURE);
	}

	while ((byte_read = getline(&line_read, &line_len, fp)) != -1) {
		line_read[byte_read - 1] = '\0';
		int bptr = 0, eptr = 0;
		n = 0;

		for (int i = 0; i < byte_read; i++) {
			if (isblank(line_read[i]) || line_read[i] == '\0') {
				eptr = i - 1;
				char* str = (char *) malloc((eptr - bptr + 2) * sizeof(char));
				str = strncpy(str, &line_read[bptr], eptr - bptr + 1);
				str[eptr - bptr + 1] = '\0';
				in->ptr[m][n++] = atoi(str);

				if (n + 1 > in->cols)
					addsize_int_2d_arr_or_die(in, 0, n);

				free(str);

				while (isblank(line_read[++i]))
					;
				bptr = i;
			}
		}

		m++;

		if (m + 1 > in->rows)
			addsize_int_2d_arr_or_die(in, m, 0);
	}

	in->rows = m;
	in->cols = n;

	fclose(fp);
	if (line_read)
		free(line_read);
}
