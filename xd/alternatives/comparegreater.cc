#include "alternatives.ih"

// called from setHistory
    // true: first < second, smallest elements are put first
    // return false to put the largest elements first

bool Alternatives::compareGreater(HistoryInfo const &first, 
                                  HistoryInfo const &second)
{
    if (first.path.empty())
        return false;
    if (second.path.empty())
        return true;

    return second.count - first.count;
}
