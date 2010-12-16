#include "arbiter.ih"

size_t Arbiter::show(size_t begin, char first, char last) const
{
    size_t end = min(begin + last - first + 1, d_alternatives.size());

    size_t intermediate = d_alternatives.separateAt();

    for (; begin != end; ++begin, ++first)
    {
        if (begin == intermediate)
            cerr << '\n';
        cerr << setw(2) << first << ": " << d_alternatives[begin] << '\n';
    }

    return begin;
}





