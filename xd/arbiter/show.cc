#include "arbiter.ih"

size_t Arbiter::show(size_t begin, char first, char last) const
{
    size_t end = min(begin + last - first + 1, 
                     d_alternatives.size());

    size_t intermediate = d_alternatives.separateAt();

    if (begin <= intermediate && intermediate <= end)
    {
        for (; begin != intermediate; ++begin, ++first)
            cerr << setw(2) << first << ": " << d_alternatives[begin] << '\n';

        cerr << '\n';
    }

    for (; begin != end; ++begin, ++first)
        cerr << setw(2) << first << ": " << d_alternatives[begin] << '\n';

    return begin;
}





