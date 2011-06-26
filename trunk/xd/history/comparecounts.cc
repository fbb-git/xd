#include "history.ih"

// called from load
    // true: first < second, smallest elements are put first
    // return false to put the largest elements first

bool History::compareCounts(HistoryInfo const &first, 
                            HistoryInfo const &second)
{
    return second.count < first.count;
}
