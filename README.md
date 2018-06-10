# declos

Declare and run a closure-like nested function in C, based on `setjmp.h`.  It
does not provide different ways of capturings (e.g. by-value, by-reference),
only concerned with the *upvalues*.

**Disclaimer:** Definitely unsafe.  Use with your helmets on.

## Usage

```c
#include <stdio.h>
#include "declos.h"

int a = 42;

int
main()
{
    int b = 69;

    declos(foo, {
        ++a; ++b;
    });

    printf("a=%d, b=%d\n", a, b); // a=42, b=69
    clos_run(foo);
    printf("a=%d, b=%d\n", a, b); // a=42, b=70

    return 0;
}
```

## License

MIT
