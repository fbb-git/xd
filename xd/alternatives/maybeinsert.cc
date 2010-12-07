#include "alternatives.ih"

void Alternatives::maybeInsert(HistoryLine const &hl, vector<string> &history, 
                               size_t oldestTime) 
{
    if (hl.path.empty())
        return;

    if (oldestTime <= hl.time)
        history.push_back(hl);
}
