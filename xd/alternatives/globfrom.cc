#include "alternatives.ih"

Alternatives::ViableResult Alternatives::globFrom(string initial)
{
    GlobContext context = {*this};

    if (not d_arg.option('a'))
    {
        auto iters = d_arg.beginEndRE("^\\s*ignore\\s+\\S+\\s*$");
        
        for (auto &line: ranger(iters.first, iters.second))
                addIgnored(line, context.ignore);
    }

    ViableResult (Alternatives::*globFun)(string dir, GlobContext &context) = 
        d_arg.option('g') && !d_arg.option(0, "traditional") ? 
            &Alternatives::generalizedGlob
        : 
            &Alternatives::glob;

    ViableResult vr = (this->*globFun)(initial, context);

    if (d_addRoot == TRUE || (size() == 0 && d_addRoot == IF_EMPTY))
        vr = (this->*globFun)("/", context);

    if (vr == ONLY_CD)
        cout << initial << endl;

    return vr;
}

