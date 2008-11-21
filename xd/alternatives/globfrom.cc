#include "alternatives.ih"

void Alternatives::globFrom(string initial)
{
    GlobContext context = {*this};

    if (not d_arg.option('a'))
        for_each(d_arg.beginRE("^\\s*ignore\\s+\\S+\\s*$"),
             d_arg.endRE(), FnWrap1c<string const &, std::set<string> &>
                                (addIgnored, context.ignore));

    (this->*(d_arg.option('m') ? 
                &Alternatives::globMerged 
            : 
                &Alternatives::glob)
    )(initial, context);

    if (d_addRoot == TRUE || (size() == 0 && d_addRoot == IF_EMPTY))
        glob("/", context);
}

