#include "alternatives.ih"

void Alternatives::globFrom(string initial)
{
    std::set<pair<size_t, size_t> > stored;

    glob(initial, stored);

    if (d_addRoot == TRUE || (size() == 0 && d_addRoot == IF_EMPTY))
        glob("/", stored);
}

