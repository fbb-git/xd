#include "icerror.h"

ICError const &ICError::operator=(ICError const &right)
{
	if (this != &right)
	{
		delete program;
		stream = right.stream;
		setprogram(right.program);
    	}
	return (*this);
}
