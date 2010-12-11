#include "alternatives.ih"

Alternatives::Alternatives()
:
    d_homeDir(getHome()),
    d_arg(configFile()),
    d_nInHistory(0),
    d_History(d_arg, d_homeDir)
{}
