#include "alternatives.ih"

void Alternatives::globFrom(string initial)
{
    GlobContext context = {*this};

    if (not d_arg.option('a'))
        for_each(d_arg.beginRE("^\\s*ignore\\s+\\S+\\s*$"),
             d_arg.endRE(), FnWrap1c<string const &, std::set<string> &>
                                (addIgnored, context.ignore));

    void (Alternatives::*globFun)(string dir, GlobContext &context) = 
        d_arg.option('g') ? 
            &Alternatives::generalizedGlob
        : 
            &Alternatives::glob;

    (this->*globFun)(initial, context);

    if (d_addRoot == TRUE || (size() == 0 && d_addRoot == IF_EMPTY))
        (this->*globFun)("/", context);
}

