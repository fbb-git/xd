#include "icerror.h"

int ICError::message(char const *fmt, ...)
{
	va_list
		args;

	va_start(args, fmt);
	msg(fmt, args);
	
	return (1);
}
