#include "icstring.h"

ICString::ICString(ICString const &other)
{
    copy(other.count, other.vector);		// copy the other one
}
