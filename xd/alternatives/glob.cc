#include "alternatives.ih"

void Alternatives::glob(string dir, GlobContext &context)
try
{
    for (auto &element: d_command)
        (dir += element) += "*/";                   // add */ to each cmd arg

    dir.resize(dir.length() - 1);                   // remove trailing /

    imsg << "Passing `" << dir << "' to glob" << endl;

                                                    // find matching elements
    Glob glob(Glob::DIRECTORY, dir, Glob::NOSORT, Glob::DEFAULT);

    for (auto entry: glob)
        globFilter(entry, context);                 // accept unique dirs.
}
catch (exception const &exc)
{}






