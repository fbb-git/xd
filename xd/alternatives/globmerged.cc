#include "alternatives.ih"

void Alternatives::globMerged(string initial, GlobContext &context)
{
        // create the command consisting of all cmd line args
    string searchCmd = d_command.accumulate();

    msg() << "Merged search command: `" << searchCmd << '\'' << info;

    globHead(initial, searchCmd, context);
}
