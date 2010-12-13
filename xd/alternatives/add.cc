#include "alternatives.ih"

void Alternatives::add(char const *entry)
{
cerr << "CALLING add\n";

    if (not d_history.find(entry))
        push_back(entry);
    else
    {
        push_front(entry);
cerr << "ADDING\n";
        ++d_nInHistory;
    }
}
