#include "icerror.h"

ICError::ICError(FILE *str, char const *prog)
{
	stream = str;
	program = 0;
	setprogram(prog);
}
