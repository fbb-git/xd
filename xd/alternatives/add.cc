#include "alternatives.ih"

void Alternatives::add(char const *entry)
{
    if (findHistory(entry) == d_history.end())
        push_back(entry);
    else
    {
        push_front(entry);
        ++d_nHistory;
    }
}
