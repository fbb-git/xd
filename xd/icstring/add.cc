#include "icstring.h"

void ICString::add(char const *str)
{
						// room for next element
	vector = (char **)realloc(vector, (count + 1) * sizeof(char *));
	vector [count] = strdup(str);		// stroy a duplicate
	count++;				// increment the counter
}
