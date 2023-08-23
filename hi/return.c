#include "test.h"

void returnn()
{
	extern int var;

	var = 100;

	printf("Return has changed var back to %d\n", var);

}
