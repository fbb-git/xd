#include "alternatives.ih"

void Alternatives::add(char const *entry)
{
    if (findPopular(entry) == d_popular.end())
        push_back(entry);
    else
    {
        push_front(entry);
        ++d_nPopular;
    }
}
