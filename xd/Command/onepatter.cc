#include "Command.h"

void Command::one_pattern(char *cp)
{
	char
		*pp;

	pp = pattern + strlen(pattern);
	
	while (*cp)
	{
		*pp++ = *cp++;		// copy a char
		*pp++ = '*';		// append '*'
		*pp++ = '/';		// append '/'
	}
	*pp = 0;			// terminate the string
}

