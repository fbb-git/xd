#include "alternatives.ih"

void Alternatives::globFrom(string initial)
{
    GlobContext context = {*this};

    if (not d_arg.option('a'))
    {
        auto iterators = d_arg.beginEndRE("^\\s*ignore\\s+\\S+\\s*$");
        
        for_each(
            iterators.first, iterators.second, 
            [&](std::string const &line)
            {
                addIgnored(line, context.ignore);
            }
        );
    }

    void (Alternatives::*globFun)(string dir, GlobContext &context) = 
        d_arg.option('g') && !d_arg.option(0, "traditional") ? 
            &Alternatives::generalizedGlob
        : 
            &Alternatives::glob;

    (this->*globFun)(initial, context);

    if (d_addRoot == TRUE || (size() == 0 && d_addRoot == IF_EMPTY))
        (this->*globFun)("/", context);
}

