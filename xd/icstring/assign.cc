#include "icstring.h"

ICString const &ICString::operator =(ICString const &other)
{
    if (this != &other)
	{
	    destroy();			// remove current Strings
	    copy(other.count, other.vector);	// copy the other one
	}
	return (*this);
}
