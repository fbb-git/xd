#include "configfile.h"

char const *ConfigFile::next_token(void)
{
	register char
		*ret = 0;               // suppress "uninitialized" warning

					// wp is something, and a token is found
	if (wp && (ret = strtok(0, " \t\n")))
		return (ret);		// then return the token.

	delete wp;			// remove old wp
	wp = 0;

	return (0);			// return nothing
}	
