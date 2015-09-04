#include <stdio.h>
#include "pb_0001.h"

int pb_0001(int MaxVal) {
int sum = 0;

for(int i=0; i <=MaxVal;i++)
	if (!(i % 3) || !(i %5))
		sum +=i;

return sum;

}
