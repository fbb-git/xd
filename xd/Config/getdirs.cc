#include "Config.h"

Config::Dirs Config::get_dirsparam() const
{
#ifdef DEBUG
    fprintf(stderr, "dir in Config::get_dirsparam() %x\n", (unsigned)dirs);
#endif
	return(dirs);
}

		
