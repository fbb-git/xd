#include "configfile.h"

void ConfigFile::readfile(FILE *stream)
{
	char
		*token,
		*dup,
		buf[512];

	while (fgets(buf, 512, stream))	// read a line
	{
		dup = strdup(buf);			// working copy
		if
		(
			(token = strtok(buf, " \t\n"))	// token ?
			&&
			*token != '#'			// but no comment ?
		)
			add(dup);			// then store
		delete dup;				// ready with the copy
	}
}	
