#include "icerror.h"

ICError::~ICError()
{
	delete program;
}
