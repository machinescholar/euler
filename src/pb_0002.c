#include <stdio.h>
#include "pb_0002.h"

long pb_0002(long UpLmt) {
	long frsFib = 1, sndFib = 1, nxtFib = 0, sum = 0;

	nxtFib = frsFib + sndFib;

	while (nxtFib <= UpLmt) {
		if (!(nxtFib % 2))
			sum += nxtFib;

		frsFib = sndFib;
		sndFib = nxtFib;
		nxtFib = frsFib + sndFib;
	}

	return sum;

}
