#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

void destroy_int_2d_arr(int_2d_arr* in) {

	for (int i = 0; i < in->rows; i++)
		free(in->ptr[i]);
	free(in->ptr);
	free(in);
}

char_2d_arr* create_char_2d_arr_or_die(int rlen, int clen) {
	char_2d_arr* c2a = (char_2d_arr *) malloc(sizeof(char_2d_arr));
	c2a->rlen = rlen;
	c2a->clen = clen;

	c2a->ptr = (char**) malloc(rlen * sizeof(char*));
	if (c2a == NULL) {
		fprintf(stderr, "Can not allocate c2a->ptr...\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < rlen; i++)
		c2a->ptr[i] = (char *) malloc(clen * sizeof(char));

	for (int i = 0; i < rlen; i++) {
		for (int j = 0; j < clen; j++)
			c2a->ptr[i][j] = ' ';
	}

	return c2a;
}

char_2d_arr* addsize_char_2d_arr(char_2d_arr* c2a, int ylen, int xlen) {
	int o_rlen = c2a->rlen, o_clen = c2a->clen;

	if (ylen > 0) {
		c2a->ptr = (char **) realloc((char**) c2a->ptr,
				(c2a->rlen + ylen) * sizeof(char *));
		if (c2a->ptr == NULL) {
			fprintf(stderr, "Cannot realloc c2a->ptr..\n.");
			exit(EXIT_FAILURE);
		}

		for (int i = c2a->rlen; i < c2a->rlen + ylen; i++) {
			c2a->ptr[i] = (char *) malloc(c2a->clen * sizeof(char));

			for (int j = 0; j < c2a->clen; j++)
				c2a->ptr[i][j] = ' ';
		}

		c2a->rlen += ylen;
	}

	if (xlen > 0) {
		for (int i = 0; i < c2a->rlen; i++) {
			c2a->ptr[i] = (char *) realloc((char*) c2a->ptr[i],
					(c2a->clen + xlen) * sizeof(char));

			if (c2a->ptr[i] == NULL) {
				fprintf(stderr, "Cannot realloc c2a->ptr[]..\n.");
				exit(EXIT_FAILURE);
			}
		}

		c2a->clen += xlen;
	}

	return c2a;
}

void destroy_char_2d_arr(char_2d_arr* c2a) {
	for (int i = 0; i < c2a->rlen; i++)
		free(c2a->ptr[i]);
	free(c2a->ptr);
	free(c2a);
}

int_2d_arr* create_int_2d_arr_or_die(int rows, int cols) {
	if (rows == 0 && cols == 0)
		return NULL;

	int_2d_arr* out = (int_2d_arr*) malloc(sizeof(int_2d_arr));
	if (out == NULL) {
		fprintf(stderr, "Cant malloc int_2d_arr...");
		exit(EXIT_FAILURE);
	}

	out->ptr = (int**) malloc(rows * sizeof(int*));
	if (out->ptr == NULL) {
		fprintf(stderr, "Cant malloc out->ptr...");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < rows; i++) {
		out->ptr[i] = (int *) malloc(cols * sizeof(int));
		if (out->ptr[i] == NULL) {
			fprintf(stderr, "Can not malloc out->ptr[]...");
			exit(EXIT_FAILURE);
		}
	}

	out->cols = cols;
	out->rows = rows;

	return out;

}

int_2d_arr* addsize_int_2d_arr_or_die(int_2d_arr* in, int inc_r, int inc_c) {
	if (inc_r > 0) {
		in->ptr = (int**) realloc(in->ptr, (in->rows + inc_r) * sizeof(int*));
		in->rows += inc_r;

		for (int i = in->rows - 1; i >= in->rows - inc_r; i--)
			in->ptr[i] = (int *) malloc(in->cols * sizeof(int));

		if (in->ptr == NULL) {
			fprintf(stderr, "Can not realloc in->ptr...");
			exit(EXIT_FAILURE);
		}
	}

	if (inc_c > 0) {
		for (int i = 0; i < in->rows; i++) {
			in->ptr[i] = (int *) realloc(in->ptr[i],
					(in->cols + inc_c) * sizeof(int));

			if (in->ptr[i] == NULL) {
				fprintf(stderr, "Cannot relloac in->ptr[]...");
				exit(EXIT_FAILURE);
			}
		}
		in->cols += inc_c;
	}
	return in;
}
