#include "alternatives.ih"

void Alternatives::order()
{
    if (not d_history.rotate())
        return;

cerr << "Rotating: " << 0 << ' ' << d_nInHistory << ' ' << size() << '\n';

    rotate(begin(), begin() + d_nInHistory, end());
}
