#include "alternatives.ih"

void Alternatives::order()
{
    if (not d_History.rotate())
        return;

    rotate(begin(), begin() + d_nInHistory, end());
}
