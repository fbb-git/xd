#include "alternatives.ih"

void Alternatives::globFrom(string initial)
{
    GlobContext context = {*this};

    if (not Arg::instance().option('a'))
        for_each(d_config.beginRE("^\\s*ignore\\s+\\S+\\s*$"),
             d_config.endRE(), FnWrap1c<string const &, std::set<string> &>
                                (addIgnored, context.ignore));

    glob(initial, context);

    if (d_addRoot == TRUE || (size() == 0 && d_addRoot == IF_EMPTY))
        glob("/", context);
}

