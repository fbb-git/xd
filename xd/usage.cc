/*
                                U S A G E . C P P
*/

#include "xd.h"


#define	VERSION	"2.12"
#define YEAR	"1994-1996"

void usage(Args const &args)
{
	char const
		*prog;

	prog = args.get_progname();

	ICError
		icerror(prog);
	
	icerror.copyright("eXchange Directory ++", VERSION, YEAR, 1);

	fprintf(stderr,
	"%s by Frank B. Brokken\n"
	"\n"
        "Usage: %s args\n"
        "Where:\n"
        "   args:  arguments, possibly containing directory separators [/-].\n"
        "\n"
		
	"%s++ eXchanges Directories by interpreting the characters of its\n"
	"argument(s) as the initial characters of nested subdirectories.\n"
	"Multiple arguments or arguments separated by / or - define the\n"
	"initial characters of subsequently nested subdirectories.\n"
	"\n"
	"If the first argument starts with . expansion starts at the current\n"
	"directory; if it's # (# in [0-9]) expansion starts at parent #\n"
	"\n"
        "When the specification results in multiple solutions, a final\n"
        "selection is requested from a displayed list of alternatives.\n"
	"\n"
	"If $HOME" XD_CONF_PATH " contains  `home no'  normal expansions will\n"
	"start at the / directory, rather than at $HOME/.\n"
	"\n"
	"By default an extra expansion is tried starting from the / directory\n"
	"if the expansion from  $HOME/ fails. Use `extra no' to prevent this.\n"
	"Use `extra always' to get it always\n"
	"\n"
	    , prog
	    , prog
            , prog
        );
}
