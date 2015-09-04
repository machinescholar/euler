#include <stdio.h>
#include "pb_0003.h"

uint64_t pb_0003(uint64_t lgrNum) {
	uint64_t maxDiv;
	long curDiv = 2;

	while (lgrNum != 1) {
		if (!(lgrNum % curDiv))
			lgrNum = lgrNum / curDiv;
		else curDiv++;
	}

	return curDiv;
}
