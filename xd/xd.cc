/*                              xd.cc

   A C++ main()-frame generated by cpp.im for xd.cc

*/

#include "xd.h"               // program header file


int main(int argc, char **argv, char **envp)
{
	Args
		args(argc, argv);		// preprocess the arguments
#ifdef DEBUG
	fprintf(stderr, "main():\t args defined\n");
#   endif

	Config
		config;				// read the configuration
#ifdef DEBUG
	fprintf(stderr, "main():\t config defined\n");
#   endif

	Command
		command(args, config);		// build a command from args
#ifdef DEBUG
	fprintf(stderr, "main():\t command defined\n");
#   endif
						// and config

	if (args.get_count() == 1)		// only one argument ?
	{
                usage(args);			// usage/copyright on no args
		return (command.write("."));
	}

	Match
		match(command.get_pattern(),	// make the matches
			config);
#ifdef DEBUG
	fprintf(stderr, "main():\t match defined\n");
#   endif

	Arbiter
		arbiter(match);			// Make the decision
#ifdef DEBUG
	fprintf(stderr, "main():\t arbiter defined\n");
#   endif

	return(command.write(arbiter.get_choice()));// Write the cmd to file
}
