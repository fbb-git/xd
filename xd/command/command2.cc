#include "command.ih"

Command::~Command()
{
	delete command;			// remove the command-buffer
	delete pattern;			// delete the pattern
}
