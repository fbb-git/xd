#include "noncanon.h"

char NonCanon::get(void) const
{
	char
		c;

	read(STDIN_FILENO, &c, 1);	// read the char
	if (use_echo)
	{
                printf("%c", c);
		fflush(stdout);
	}
	return (c);			
}

