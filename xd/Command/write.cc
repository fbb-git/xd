#include "Command.h"

int Command::write(char const *path)
{
	printf("%s\n", path);			// write the selected path
	return (!strcmp(path, "."));		// ret. 0 for real paths
}

	
	
