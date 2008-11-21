#include "alternatives.ih"

void Alternatives::glob(string dir, GlobContext &context)
try
{
    for_each(d_command.begin(), d_command.end(),    // add */ to each cmd arg
            FnWrap1c<string const &, string &>(addPath, dir));

    dir.resize(dir.length() - 1);                   // remove trailing /

    msg() << "Passing `" << dir << "' to glob" << info;

    Glob glob(dir, Glob::NOSORT, Glob::DEFAULT);    // find matching elements
    // verify() not called since we're ignoring exceptions here

    for_each(glob.begin(), glob.end(),              // accept unique dirs.
             FnWrap1c<char const *, GlobContext &>(globFilter, context));
}
catch (Errno const &err)      // to catch the exception from glob
{}
