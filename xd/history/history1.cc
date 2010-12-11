#include "history.ih"

History::History(ArgConfig &arg, string const &homeDir)
:
    d_arg(arg),
    d_now(time(0)),
    d_begin(0),
    d_end(0)
{
    load(homeDir);
    setData();
}
