#include "alternatives.ih"

void Alternatives::order()
{
    if (not d_history.rotate())
        return;

    rotate(begin(), begin() + d_nInHistory, end());
}
