#include "history.ih"

void History::maybeInsert(HistoryInfo const &hi, 
                          vector<HistoryInfo> &history, size_t oldestTime) 
{
    if (hi.path.empty())
        return;

    if (oldestTime <= hi.time)
        history.push_back(hi);
}
