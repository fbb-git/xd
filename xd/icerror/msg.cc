#include "icerror.h"

void ICError::msg(char const *fmt, va_list args)
{
        fprintf(stream, "%s", program);
	vfprintf(stream, fmt, args);
	fputc('\n', stream);
}
