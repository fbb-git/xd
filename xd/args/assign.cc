#include "args.h"

Args const &Args::operator =(Args const &other)
{
    if (this != &other)
	{
		(ICString &)*this = other;	// copy 'other' part
		destroy();			// delete part of this class
		copy(get_string(0));		//  copy part of this class
	}
	return (*this);
}

