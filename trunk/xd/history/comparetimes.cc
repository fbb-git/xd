#include "history.ih"

bool History::compareTimes(HistoryInfo const &first, 
                           HistoryInfo const &second)
{
    return  second.time < first.time;
}
