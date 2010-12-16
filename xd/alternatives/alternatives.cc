#include "alternatives.ih"

Alternatives::Alternatives()
:
    d_homeDir(getHome()),
    d_arg(configFile()),
    d_nInHistory(0),
    d_history(d_arg, d_homeDir)
{
    d_separate = d_arg.option(0, "history-separate");
    cerr << "Alternatives\n";
}
