#include "icstring.h"

void ICString::destroy()
{
    while (count--)
	free (vector[count]);		// free the elements

    free (vector);			// free the vector
}
