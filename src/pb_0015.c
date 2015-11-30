#include <stdio.h>
#include <time.h>
#include "pb_0015.h"

const int GRID_SIZE = 20;

long pb_0015() {
	clock_t beg, end;

	beg = clock();
	long output[GRID_SIZE + 1][GRID_SIZE + 1];

	for (int i = 0; i < GRID_SIZE + 1; i++)
		for (int j = 0; j < GRID_SIZE + 1; j++)
			output[i][j] = 0;

	for (int i = 0; i < GRID_SIZE + 1; i++) {
		for (int j = 0; j < GRID_SIZE + 1; j++)
			output[i][j] = 0;

		printf("\n");
	}

	long result = nav_lattice(output, 0, 0, GRID_SIZE);
	end = clock();
	printf("Execution time of pb_0015 is %f\n",
			(double) (end - beg) / CLOCKS_PER_SEC);
	return result;
}

long nav_lattice(long output[][GRID_SIZE + 1], int i, int j, int GRID_SIZE) {
	long path1 = 0, path2 = 0;
	printf("%d %d\n", i, j);

	if (i == GRID_SIZE && j == GRID_SIZE) {
		output[i][j] = 1;
		return 1;
	}

	if (i + 1 <= GRID_SIZE)
		if (output[i + 1][j] != 0)
			path1 = output[i + 1][j];
		else
			path1 = nav_lattice(output, i + 1, j, GRID_SIZE);

	if (j + 1 <= GRID_SIZE)
		if (output[i][j + 1] != 0)
			path2 = output[i][j + 1];
		else
			path2 = nav_lattice(output, i, j + 1, GRID_SIZE);

	output[i][j] = path1 + path2;

	return output[i][j];
}
