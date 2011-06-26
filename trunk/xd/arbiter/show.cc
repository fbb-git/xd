#include "arbiter.ih"

size_t Arbiter::show(size_t begin, char first, char last, size_t separateAt) 
                                                                        const
{
    size_t end = min(begin + last - first + 1, d_alternatives.size());

    for (; begin != end; ++begin, ++first)
    {
        if (begin == separateAt)
            cerr << '\n';
        cerr << setw(2) << first << ": " << d_alternatives[begin] << '\n';
    }

    return begin;
}





