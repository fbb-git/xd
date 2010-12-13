#include "history.ih"

void History::maybeInsert(HistoryInfo const &hi, 
                          vector<HistoryInfo> &history, size_t oldestTime) 
{
cerr << hi.path << " read\n";
    if (hi.path.empty())
        return;

    if (oldestTime <= hi.time)
    {
cerr << hi.path << " into the history\n";
        history.push_back(hi);
}
}
