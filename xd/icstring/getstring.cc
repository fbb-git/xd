#include "icstring.h"

char const *ICString::get_string(unsigned index) const
{
	return
	(
		count > index ?		      // return existing string
			vector[index]
		:
			0			// or 0
	);
}
