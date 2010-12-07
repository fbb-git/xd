#include "alternatives.ih"

void Alternatives::order()
{
    if (d_historyName.empty() || d_nHistory == 0 || d_historyFirst)
        return;

    rotate(begin(), begin() + d_nHistory, end());
}
