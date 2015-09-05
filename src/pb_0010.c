#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pb_0010.h"

long pb_0010_alt() {
	clock_t begin, end;

	begin = clock();
	const int MAX = 2000000;
	list* prime_list;
	long sum = 2;

	prime_list = list_create();
	list_append(prime_list, 2);
	for (long i = 3; i < MAX; i += 2) {
		if (is_prime_adv(prime_list, i)) {
			list_append(prime_list, i);
			sum += i;
			printf("%d\n", prime_list->length);
		}
	}

	printf("%ld\n", sum);
	//list_destroy(prime_list);
	end = clock();
	printf("The execution of pb_0009 is %f\n",
			(double) (end - begin) / CLOCKS_PER_SEC);
	return sum;

}

long pb_0010() {
	//Using Sieve of Eratosthene method
	clock_t begin,end;
	begin=clock();
	const int MAX = 2000000;
	int prime_tab[MAX];
	long sum = 0;

	for (int i = 0; i < MAX; i++)
		prime_tab[i] = 1; //Assume all are primes

	prime_tab[0] = 0;
	prime_tab[1] = 0; //start finding which numbers are not primes

	//Multiples of 2 are not prime
	for(int j=2; 2*j <= MAX;j++)
		prime_tab[2*j] = 0;

	//Multiples of primes are not primes
	for(int i=3;i*i <= MAX; i+=2)
		if (prime_tab[i])
			for(int j=2;i*j <= MAX;j++)
				prime_tab[i*j] = 0;

	for(int i=0;i< MAX;i++)
		if (prime_tab[i])
			sum+=i;

	end=clock();
	printf("Problem pb_0010 takes %f\n",(double)(end-begin)/CLOCKS_PER_SEC);

	return sum;
}

bool is_prime_adv(list* pl, long next_prime) {
	node* curnode = pl->head;
	int tmp_prime;

	while (curnode != NULL) {
		tmp_prime = (*curnode).val;

		if (tmp_prime * tmp_prime > next_prime)
			break;
		else if (next_prime % tmp_prime == 0)
			return false;

		curnode = curnode->next;
	}

	return true;
}
