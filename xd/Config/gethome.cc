#include "Config.h"

char const *Config::get_home(void) const
{
	if (homeparam == from_HOME)
		return(home);			// start looking at 'home'
	return ("/");				// start looking at root
}

		
