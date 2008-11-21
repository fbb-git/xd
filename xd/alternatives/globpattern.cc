#include "alternatives.ih"

void Alternatives::globPattern(string pattern, 
                                string const &searchCmd, size_t idx,
                                GlobContext &context)
try
{
        // create a pattern from pattern + initial substring
    pattern += searchCmd.substr(0, idx);
    pattern += "*/";

    if (idx != searchCmd.length())
        globHead(pattern, searchCmd.substr(idx), context);
    else
    {
        msg() << "Globbing merged pattern `" << pattern << '\'' << info;
        Glob glob(pattern, Glob::NOSORT, Glob::DEFAULT);
        // verify() not called since we're ignoring exceptions here

        for_each(glob.begin(), glob.end(), 
             FnWrap1c<char const *, GlobContext &>(globFilter, context));
   }
}
catch (Errno const &err)      // to catch exceptions from glob
{}


