#include "icstring.h"

void ICString::setup(unsigned cnt, char const *const *vec)
{
	destroy();			// kill off old info
	copy(cnt, vec);
}
