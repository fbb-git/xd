#include "icerror.h"

void ICError::setprogram(char const *prog)
{
	delete program;
	
	if (prog)				// private function, used only
	{					// when program is free to use
		char				// either empty string, or the
			buf[200];		// program name is set in 
						// program
		sprintf(buf, "%s: ", prog);
		program = strdup(buf);
	}
	else
		program = strdup("");

	
}
