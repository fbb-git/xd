#include "alternatives.ih"

void Alternatives::generalizedGlob(string initial, GlobContext &context)
{
        // create the command consisting of all cmd line args
    string searchCmd = d_command.accumulate();
    searchCmd.resize(searchCmd.length() - 1);           // remove trailing /


    imsg << "Merged search command: `" << searchCmd << '\'' << endl;

    globHead(initial, searchCmd, context);
}
