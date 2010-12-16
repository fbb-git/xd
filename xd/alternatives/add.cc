#include "alternatives.ih"

void Alternatives::add(char const *entry)
{
    if (not d_history.find(entry))
        push_back(entry);
    else
    {
        push_front(entry);
        ++d_nInHistory;
    }
}
