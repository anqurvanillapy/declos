#ifndef _DECLOS_H
#define _DECLOS_H

#include <setjmp.h>

typedef jmp_buf clos_t;

#define declos(name, body)              \
	clos_t __clos_in_##name;            \
	clos_t __clos_out_##name;           \
	if (setjmp(__clos_in_##name)) {     \
		body;                           \
		longjmp(__clos_out_##name, 1);  \
	}

#define clos_run(name) \
	if (!setjmp(__clos_out_##name)) longjmp(__clos_in_##name, 1);

#endif /* !_DECLOS_H */
