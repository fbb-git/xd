#include "alternatives.ih"

#include <iterator>

void Alternatives::globFrom(string initial)
{
    for_each(d_command.begin(), d_command.end(),
            FnWrap1c<string const &, string &>(addPath, initial));

    initial.resize(initial.length() - 1);   // remove trailing /

    Glob glob(initial, Glob::NOSORT, Glob::DEFAULT);

    std::set<pair<size_t, size_t> > stored;

    GlobContext context = {stored, *this};

    for_each(glob.begin(), glob.end(), 
             FnWrap1c<char const *, GlobContext &>(globFilter, context));

    copy(begin(), end(), ostream_iterator<string>(cerr, "\n"));

}
