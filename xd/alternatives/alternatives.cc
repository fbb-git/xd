#include "alternatives.ih"

Alternatives::Alternatives()
:
    d_arg(Arg::instance()),
    d_ok(d_config),
    d_debug(d_arg.option(0, "debug"))
{}








