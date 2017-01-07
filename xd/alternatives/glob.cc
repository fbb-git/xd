#include "alternatives.ih"

Alternatives::ViableResult Alternatives::glob(string dir, GlobContext &context)
try
{
    if (d_command.empty())
        return ONLY_CD;

    for (auto &element: d_command)
        (dir += element) += "*/";                   // add */ to each cmd arg

    dir.resize(dir.length() - 1);                   // remove trailing /

    imsg << "Passing `" << dir << "' to glob" << endl;

                                                    // find matching elements
    Glob glob(Glob::DIRECTORY, dir, Glob::NOSORT, Glob::DEFAULT);

    for (auto entry: glob)
        globFilter(entry, context);                 // accept unique dirs.
    
    return RECEIVED_ALTERNATIVES;
}
catch (exception const &exc)
{
    return RECEIVED_ALTERNATIVES;
}






