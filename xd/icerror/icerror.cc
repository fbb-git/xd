#include "icerror.h"

ICError::ICError(char const *prog)
{
	stream = stderr;
	program = 0;

	setprogram(prog);
}
