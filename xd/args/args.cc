#include "args.h"

Args::Args(unsigned argc, char const *const *argv)
{
	setup(argc, argv);		// do part of ICString
	copy(argv[0]);		// copy info of this class
}

