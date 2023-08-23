#include "test.h"

int change(void)
{
	extern int var;

	var = 150;

	printf("var in func change = %d\n", var);

	return (0);
}
