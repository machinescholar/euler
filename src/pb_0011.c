#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pb_0011.h"
#include "commath.h"

int** init_in_array_or_die(const char *path, int* rows, int* columns) {
	const int INIT_SIZE = 10;
	const int INCREMENT = 10;

	FILE* fp;
	char* line_read = NULL;
	int x_cnt = 0, y_cnt = 0, x_len = 0, y_len = 0;
	int** in_arr;
	size_t byte_read, line_len;

	//initialize the array
	in_arr = (int **) malloc(INIT_SIZE * sizeof(int*));
	y_len = INIT_SIZE;

	for (int i = 0; i < y_len; i++)
		in_arr[i] = (int *) malloc(INIT_SIZE * sizeof(int));

	x_len = INIT_SIZE;

	for (int i = 0; i < y_len; i++)
		for (int j = 0; j < x_len; j++)
			in_arr[i][j] = 0;

	fp = fopen(path, "r");
	if (fp == NULL) {
		fprintf(stderr, "File %s can not be open. Exit program...!!!", path);
		exit(EXIT_FAILURE);
	}

	while ((byte_read = getline(&line_read, &line_len, fp)) != -1) {
		char *beg_ptr, *end_ptr;
		char* str_num;
		int num;

		line_read[byte_read - 1] = '\0';

		if (y_cnt + 1 > y_len) {
			in_arr = (int **) realloc(in_arr,
					(y_len + INCREMENT) * sizeof(int*));

			for (int i = y_len; i < y_len + INCREMENT; i++)
				in_arr[i] = (int *) malloc(x_len * sizeof(int));

			for (int i = y_len; i < y_len + INCREMENT; i++)
				for (int j = 0; j < x_len; j++)
					in_arr[i][j] = 0;

			y_len = y_len + INCREMENT;
		}

		beg_ptr = line_read;
		end_ptr = line_read;
		x_cnt = 0;

		while (*beg_ptr != '\0') {
			while (!isblank(*end_ptr) && *end_ptr != '\0')
				end_ptr++;

			str_num = (char *) malloc((end_ptr - beg_ptr + 1) * sizeof(char));

			memcpy(str_num, beg_ptr, end_ptr - beg_ptr);
			str_num[end_ptr - beg_ptr] = '\0';
			num = atoi(str_num);

			free(str_num);

			if (x_cnt + 1 > x_len) {
				for (int i = 0; i < y_len; i++)
					in_arr[i] = (int *) realloc((int*) in_arr[i],
							(x_len + INCREMENT) * sizeof(int));

				for (int i = 0; i < y_len; i++)
					for (int j = x_len; j < x_len + INCREMENT; j++)
						in_arr[i][j] = 0;

				x_len = x_len + INCREMENT;
			}

			in_arr[y_cnt][x_cnt] = num;
			x_cnt++;

			while (isblank(*end_ptr))
				end_ptr++;

			beg_ptr = end_ptr;
		}

		y_cnt++;
	}

	fclose(fp);
	if (line_read)
		free(line_read);

	*rows = y_cnt;
	*columns = x_cnt;
	return in_arr;
}

long pb_0011() {
	clock_t begin, end;

	begin = clock();

	const char* file_path = "/home/decreator/programs/pb_0011.txt";
	const int NEXT = 4;
	long row_prod = 1;
	long col_prod = 1;
	long dag_prod_1 = 1;
	long dag_prod_2 = 1;
	long max_prod = 1;
	int** in_arr;
	int rows, columns;

	in_arr = init_in_array_or_die(file_path, &rows, &columns);


	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
			printf("%d ", in_arr[i][j]);
		printf("\n");
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			row_prod = col_prod = dag_prod_1=dag_prod_2 = 1;

			for (int k = 0; k < NEXT; k++) {
				if (j + NEXT < columns)
					row_prod *= in_arr[i][j + k];

				if (i + NEXT < rows)
					col_prod *= in_arr[i + k][j];

				if (i + NEXT < rows && j + NEXT < columns)
					dag_prod_1 *= in_arr[i + k][j + k];

				if(i + NEXT < rows && j - NEXT >= 0)
					dag_prod_2 *= in_arr[i + k][j-k];

			}

			max_prod = max(row_prod,max(col_prod,max(dag_prod_1,max(dag_prod_2,max_prod))));
		}
	}

	for (int i = 0; i < rows; i++)
		free(in_arr[i]);

	free(in_arr);

	end = clock();
	printf("Execution of pb_0011 is %f\n",
			(double) (end - begin) / CLOCKS_PER_SEC);
	return max_prod;
}
