#include <stdio.h>
#include "declos.h"

int a = 42;

int
main()
{
	int b = 69;

	declos(foo, {
		++a;
		++b;
	});

	printf("a=%d, b=%d\n", a, b);
	clos_run(foo);
	printf("a=%d, b=%d\n", a, b);

	return 0;
}
