#include "args.h"

Args::Args(Args const &other)
     :ICString(other)
{
	prog = strdup(other.prog);
}

