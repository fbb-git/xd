#include "history.ih"

History::History(ArgConfig &arg, string const &homeDir)
:
    d_arg(arg),
    d_now(time(0))
{
    setData();
    load(homeDir);
}
