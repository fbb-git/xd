#include "alternatives.ih"

void Alternatives::glob(string dir, GlobContext &context)
try
{
    for (auto &element: d_command)
        (dir += element) += "*/";                   // add */ to each cmd arg

    dir.resize(dir.length() - 1);                   // remove trailing /

    imsg << "Passing `" << dir << "' to glob" << endl;

    Glob glob(dir, Glob::NOSORT, Glob::DEFAULT);    // find matching elements

    for (auto entry: glob)
        globFilter(entry, context);                 // accept unique dirs.
}
catch (Errno const &err)      // to catch exception from glob
{}






