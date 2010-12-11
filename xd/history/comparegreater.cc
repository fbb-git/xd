#include "history.ih"

// called from load
    // true: first < second, smallest elements are put first
    // return false to put the largest elements first

bool History::compareGreater(HistoryInfo const &first, 
                                  HistoryInfo const &second)
{
    if (first.path.empty())
        return false;
    if (second.path.empty())
        return true;

    return second.count - first.count;
}
