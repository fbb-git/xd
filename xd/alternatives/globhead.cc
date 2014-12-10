#include "alternatives.ih"

void Alternatives::globHead(string const &initial, string searchCmd,
                            GlobContext &context)
try
{
    for (size_t idx = 0; idx != searchCmd.length(); )
        globPattern(initial, searchCmd, &idx, context);
}
catch (bool headHasSlash)
{}

