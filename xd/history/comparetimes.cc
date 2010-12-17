#include "history.ih"

bool History::compareTimes(HistoryInfo const &first, 
                           HistoryInfo const &second)
{
    return  first.time < second.time;
}
