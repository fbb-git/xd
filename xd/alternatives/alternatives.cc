#include "alternatives.ih"

Alternatives::Alternatives()
:
    d_arg(ArgConfig::instance()),
    d_nHistory(0),              // 0 history alternatives encountered so far.
    d_now(time(0)),
    d_beginHistory(0),
    d_endHistory(0)
{
    setHome();
    setConfigFile();
    setHistoryLifetime();
    setHistory();
}
