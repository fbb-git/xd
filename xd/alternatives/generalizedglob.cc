#include "alternatives.ih"

Alternatives::ViableResult Alternatives::generalizedGlob(string initial, 
                                                         GlobContext &context)
{
        // create the command consisting of all cmd line args
    string searchCmd = d_command.accumulate();

    ViableResult vr = searchCmd.length() == 0 ? 
                            ONLY_CD
                        :
                            RECEIVED_ALTERNATIVES;

    if (vr == RECEIVED_ALTERNATIVES)
        searchCmd.resize(searchCmd.length() - 1);       // remove trailing /


    imsg << "Merged search command: `" << searchCmd << "'\n"
            "Starts at `" << initial << '\'' << endl;
    
    globHead(initial, searchCmd, context);

    return vr;
}
