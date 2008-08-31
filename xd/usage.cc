//                     usage.cc

#include "xd.ih"

void usage(std::string  const  &progname)
{
    cerr << "\n" <<
    progname << " by " << Icmbuild::author << "\n" <<
    progname << " V" << Icmbuild::version << " " << Icmbuild::year << "\n"
    "\n"
    "Usage: " << progname << " [options] args\n"
    "Where:\n"
    "   [options] - optional arguments (short options and default values "
                                                                    "between\n"
    "               parentheses):\n"
    "  --all (-a)                - skip `ignore' specification in the\n"
    "                              configuration file\n"
    "  --config-file (-c) <file> - path to the config file to use\n"
    "                              ($HOME/.xdrc)\n"
    "  --add-root <when>         - search expansions from /\n"
    "                              (if-empty)\n"
    "  --directories <which>     - which directories to show?\n"
    "                              (all)\n"
    "  --help (-h)               - provide this help\n"
    "  --start-at <origin>       - where to start the search?\n"
    "                              (home)\n"
    "  --version (-v)            - show version information and terminate\n"
    "  --verbose (-V)            - show " << progname << "'s actions in "
                                                                    "detail\n"
    "  args     - arguments, possibly containing directory separators [/-].\n"
    "\n" <<
    progname << 
    " eXchanges Directories by interpreting the characters of its\n"
    "argument(s) as the initial characters of nested subdirectories.\n"
    "Multiple arguments or arguments separated by / or - define the\n"
    "initial characters of subsequently nested subdirectories.\n"
    "\n"
    "If the first argument starts with . expansion starts at the current\n"
    "directory; if it's 0 expansion starts in the user's home directory;\n"
    "if it's / expansion starts at the root; if it's a number (1 .. 9) \n"
    "expansion starts at parent <number>; otherwise expansion starts\n"
    "at the location defined by the configuration file\n"
    "\n"
    "When the specification results in multiple solutions, a final\n"
    "selection is requested from a displayed list of alternatives.\n"
    "\n"
    "Use 'man xd' or read the xdrc file provided with the distribution\n"
    "for details about " <<  progname << "'s configuration file\n"
    "\n";
}
