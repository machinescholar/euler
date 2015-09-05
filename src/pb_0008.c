#include <stdio.h>
#include <stdlib.h>
#include "pb_0008.h"
#include <limits.h>

char* read_from_file(const char* path) {
	FILE* fp;
	char* line = NULL;
	char* str = NULL;
	size_t len = 0;
	size_t read;
	printf("%s\n",path);
	fp = fopen(path, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1) {
		if (str == NULL)
		{
			str = (char *) malloc(read * sizeof(char)); //must indicate read* sizeof(char) sizeof(read) wont work !!!
			line[read - 1] = '\0';
			strcpy(str,line);

			if (str==NULL){
				printf("Error! Can not Allocate str\n");
				exit(EXIT_FAILURE);
			}
		}
		else {
			str = (char *) realloc((char *)str, (strlen(str) + read) * sizeof(char));
			line[read - 1] = '\0';
			strcat(str, line);

			if (str==NULL){
				free(str);
				printf("Error! Can not ReAllocate str\n");
				exit(EXIT_FAILURE);
			}
		}
	}

	if (fp)
		fclose(fp);

	if (line)
		free(line);

	return str;
}

long pb_0008(const char* file_path) {
	const int CON_ELM = 13;
	char* str_read = read_from_file(file_path);
	long max = 0;
	long prod = 1;

	int len = strlen(str_read) -CON_ELM + 1;

	for(int i=0; i < len;i++) {
		prod = 1;

		for(int j=0;j< CON_ELM;j++)
			prod *= (long)(str_read[i + j]- '0');

		if (max < prod)
			max = prod;
	}

	free(str_read);

	return max;
}
