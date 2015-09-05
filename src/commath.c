#include <stdio.h>

int max(int a,int b) {
	return (a >b) ? a : b;
}

int min(int a,int b) {
	return (a <b)? a : b;
}

int gcd(int a,int b) {
	return b ? gcd(b, a% b) : a;
}

long lcm(int a,int b) {
	return (long) a * b / gcd(a,b);
}
