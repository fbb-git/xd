#include "Command.h"

Command::~Command()
{
	delete command;			// remove the command-buffer
	delete pattern;			// delete the pattern
}
