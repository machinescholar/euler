#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "pb_0009.h"

int pb_0009_bruteforce() {
	const int SUM = 1000;
	clock_t begin, end;

	begin = clock();

	int a = 0,b=0,c=0,k=0;

	for (int i = 1; i < SUM;i++)
		for(int j=1; j < SUM;j++) {
			k = SUM - i - j;

			c = max(max(i,j),k);
			a = min(min(i,j),k);
			b = 1000 - a - c;

			if (a*a + b*b == c*c)
			{
				end=clock();
				printf("Execution time is %f secs\n", (double)(end-begin)/CLOCKS_PER_SEC);
				return a*b*c;
			}
		}
	end = clock();
	printf("Execution time of pb_0008 is %f secs \n", (double)(end-begin)/CLOCKS_PER_SEC);

	return 0;
}

int pb_0009() {
	const int SUM = 1000;

	//Employing the fact each Pythogorean triplet can be constructed as follow
	//a=m^2-n^2 b = 2*m*n c=m^2-n^2, m > n > 0
	//gcd(a,b,c) = 1 iff gcd(m,n) = 1 and only one in (m,n) is even
	//a + b + c = SUM
	//d*(2m^2 + 2mn) = SUM --d is multiples of the triplets, take d out so that gcd(m,n)=1
	//d*2m(m + n) = SUM
	//Let k = m + n
	//We know that m < sqrt(SUM/2), m < k < 2m, m | SUM/2, k | SUM/2m, k is odd
	//Also gcd(m,k) = 1 -- otherwise exists p | m, k --> p | n --> gcd(m,n) = p > 1 -> Contradiction !
	clock_t begin,end;

	begin = clock();

	for(int m=1; m <= sqrt(SUM/2);m++) {
		if (SUM/2 % m == 0) {
			int k = (m % 2)? (m+2) : (m +1);
			for(;k < 2*m; k+=2)
				if (SUM/(2*m) % k == 0 && gcd(m,k)==1) {
					int d,a,b,c,n;
					d = SUM / 2 / k / m;

					n = k - m;
					a = d * (m*m - n*n);
					b = 2 * d * m * n;
					c=  d*(m*m + n*n);
					if (a*a + b*b == c*c) {
						end = clock();
						printf("Execution time is %f\n", (double)(end-begin)/CLOCKS_PER_SEC);
						return a * b * c;
					}
				}

		}

	}

	end = clock();
	printf("Execution time is %f\n", (double)(end-begin)/CLOCKS_PER_SEC);
	return 0;

}

