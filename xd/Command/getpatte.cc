#include "Command.h"
#include <stdio.h>

char const *Command::get_pattern()
{					// the command contains
					// /-terminated arguments
					
					// create room for the pattern
	pattern = new char [3 * strlen(command) +
				strlen(config->get_home()) + 2];

/*

	Possibilities:
	    either with or without using 'home no'. When a special case
	    arises, it is indicated.

	----------------------------------------------------------
	            		sub-specification
	----------------------------------------------------------
	intention		no			yes
	----------------------------------------------------------
	from current		.abc (11)		./a/bc (12)
							./abc
	from $HOME           	abc  (21)		-a/bc  (22)
	(using the default:   				-abc
		'home yes')
		 
	from $HOME (home no)	no special facilities. This reduces
				to entries 21/22, evaluated from
				the root.
		 
	from /			/abc (31)		/a/bc  (32)
							//abc
	from parent #		#abc (41)		#a/bc  (42)
	(#: [0-9]					#/abc
	----------------------------------------------------------

	command[0] determines the initial cell:
		.	indicates from the current directory onward
		/	indicates from the root
		-	indicates subspecifications from $HOME
		#	(#: [0-9]) indicates specifications from parent #
		other	indicates from $HOME

		any / or - beyond command[0] automatically switches to
		sub-specifications (the last / on command is not counted
		here, as this one was added by Command() itself.
		
*/		

	command [strlen(command) - 1] = 0;	// remove the / at the end.

	register char
		*next = command;		// next to look at
	register int
		sub_pattern = 0;		// sub_pattern flag
		
	switch (*next)				// do what's appropriate
	{
		case 0:				// degenerate case where
#ifdef DEBUG
	fprintf(stderr, "Command::get_pattern():\t *next == 0\n");
#endif
			strcpy(pattern, "/");	// xd / is specified
		break;
		
		case '0':			// degenerate cells 41, 42
		case '.':			// cells 11, 12
			strcpy(pattern, "./");	// start at current
			next++;			// . processed
		break;

		case '-':			// cell 22: from $HOME
			strcpy(pattern, config->get_home());
			sub_pattern++;		// forced subpatterns
			next++;
		break;

		case '/':			// cells 31, 32
			strcpy(pattern, "/");	// start from the root
/*			
			sub_pattern =		// sub-patterns for home: no
				config->get_homeparam()
				==
				Config::from_the_root;
*/				
			next++;
		break;

		case '1':			// cells 41, 42
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			*pattern = 0;		// empty pattern

						// append all parents
                        for (register int count = *next - '0'; count; count--)
				strcat(pattern, "../");
			next++;
		break;

		default:			// cell 21: all other chars
			strcpy(pattern, config->get_home());
	}

#ifdef DEBUG
	fprintf(stderr, "Command::get_pattern():\t Command: %s\n"
			"Command::get_pattern():\t Next:	%s\n",
						command, next);
#endif
			
	if
	(
		*next				// there must be something
		&&				// before it's considered
		(				// a subpattern
			sub_pattern		// sub_patt. already known ?
			||
			strpbrk(next, "-/")	// or actually found ?
		)
	)
	{
#ifdef DEBUG
		fprintf(stderr, "Command::get_pattern():\t "
					"separated pattern\n");
#endif
		separated_pattern(next);	// set up separated pattern
	}
	else
	{
#ifdef DEBUG
		fprintf(stderr, "Command::get_pattern():\t single pattern\n");
#endif
		one_pattern(next);		// set up single pattern
	}

	return (pattern);
}
