#include "icerror.h"

void ICError::fatal(char const *fmt, ...)
{
	va_list
		args;

        va_start(args, fmt);
	msg(fmt, args);			// display the msg

	exit (1);
}
