#include "noncanon.h"

NonCanon::~NonCanon()
{
	if (init)
		tcsetattr(STDIN_FILENO, TCSANOW, &saved);
}
