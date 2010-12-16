#include "alternatives.ih"

size_t Alternatives::separateAt() const
{
    if (not d_separate)
        return UINT_MAX;

    return
        d_history.position() == History::TOP ?
            d_nInHistory
        :
            size() - d_nInHistory;
}
