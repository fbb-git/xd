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
    "   [options] - optional arguments (short options between parentheses):\n"
    "  --config-file (-c) <file> - path to the config file to use\n"
    "                   ($HOME/.xdrc)\n"
    "  --debug (-d)     - provide additional info to stderr\n"
    "  --help (-h)      - provide this help\n"
    "  --version (-v)   - show version information and terminate\n"
    "  args:  arguments, possibly containing directory separators [/-].\n"
        "\n" <<
    progname << 
    " eXchanges Directories by interpreting the characters of its\n"
    "argument(s) as the initial characters of nested subdirectories.\n"
    "Multiple arguments or arguments separated by / or - define the\n"
    "initial characters of subsequently nested subdirectories.\n"
    "\n"
    "If the first argument starts with = expansion starts at the current\n"
    "directory; if it's a - expansion starts in the user's home directory\n"
    "if it's a / expansion starts at the root\n"
    "if it's a number (0 .. 9) expansion starts at parent <number>\n"
    "\n"
    "When the specification results in multiple solutions, a final\n"
    "selection is requested from a displayed list of alternatives.\n"
    "\n"
    "$HOME/.xdrc may contain:\n"
    "   home off    to start the normal expansions at the root (/) "
                                                                "directory\n"
    "               rather than at $HOME. If no solutions are found\n"
    "               an additional expansion is attempted starting from the\n"
    "               root (/) directory\n"
    "   root off    to prevent the additional expansion from the root\n"
    "   root on     the additional expansion from the root is always "
                                                            "performed\n"
    "\n";
}
