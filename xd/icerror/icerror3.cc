#include "icerror.h"

ICError::ICError(ICError const &other)
{
	stream = other.stream;
	program = 0;
	setprogram(other.program);
}
