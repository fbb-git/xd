#include "configfile.h"

ConfigFile::ConfigFile(char const *name)
	:ICString()
{
	FILE
		*stream;

	wp = 0;				// initialize the workpointer
	
	if (!(stream = fopen(name, "r")))
		return;			// Can't read the file: no configs

	readfile(stream);		// read the configfile
	fclose(stream);			// all done
}	
		
