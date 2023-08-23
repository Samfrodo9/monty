#include "test.h"

int main(void)
{
	extern int var;

	var = 100;

	printf("Var in main is %d\n", var);
	change();

	printf("Var after calling change is %d\n", var);
	var = 20;

	printf("Var in main is %d\n", var);
	returnn();

	printf("Var after calling return is %d\n", var);

	return (0);
}
