#include "arbiter.ih"

size_t Arbiter::show(size_t begin, char first, char last) const
{
    size_t end = min(begin + last - first + 1, d_alternatives.size());

    for (; begin != end; ++begin, ++first)
        cerr << setw(2) << first << ": " << d_alternatives[begin] << endl;

    return begin;
}





