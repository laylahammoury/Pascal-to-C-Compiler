//~~~~~~~~~ error.c ~~~~~~~~

#include "global.h"
char* m;
error(m) /* generates all error */
{
	fprintf(stderr, "line %d: %s\n", lineno, m);
	exit(1); /* unsuccessful termination */
}
