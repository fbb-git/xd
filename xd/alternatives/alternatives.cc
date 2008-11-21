#include "alternatives.ih"

Alternatives::Alternatives()
:
    d_arg(Arg::instance()),
    d_ok(d_config),
    d_globFun(
        set('m', "merge", s_merge, s_mergeEnd, 0) ?
            &Alternatives::globMerged
        :
            d_globFun = &Alternatives::glob
    )
{}
