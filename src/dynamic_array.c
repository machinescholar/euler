#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

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
		c2a->ptr = (char **) realloc((char**)c2a->ptr,(c2a->rlen + ylen) * sizeof(char *));
		if (c2a->ptr == NULL) {
			fprintf(stderr, "Cannot realloc c2a->ptr..\n.");
			exit(EXIT_FAILURE);
		}

		for(int i = c2a->rlen; i <  c2a->rlen + ylen;i++) {
			c2a->ptr[i] = (char *)malloc(c2a->clen * sizeof(char));

			for(int j=0; j < c2a->clen;j++)
				c2a->ptr[i][j] = ' ';
		}


		c2a->rlen += ylen;
	}

	if (xlen > 0) {
		for (int i = 0; i < c2a->rlen; i++) {
			c2a->ptr[i] = (char *) realloc((char*)c2a->ptr[i],(c2a->clen + xlen) * sizeof(char));

			if (c2a->ptr[i] == NULL) {
				fprintf(stderr, "Cannot realloc c2a->ptr[]..\n.");
				exit(EXIT_FAILURE);
			}
		}

		c2a->clen += xlen;
	}
}

void destroy_char_2d_arr(char_2d_arr* c2a) {
	for (int i = 0; i < c2a->rlen; i++)
		free(c2a->ptr[i]);

	free(c2a);
}
