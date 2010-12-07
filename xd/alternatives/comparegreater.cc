#include "alternatives.ih"

// called from setHistory
    // true: first < second, smallest elements are put first
    // return false to put the largest elements first

bool Alternatives::compareGreater(string const &first, string const &second)
{
    size_t firstPos = first.find_first_of(' ');
    size_t secondPos = second.find_first_of(' ');

    if (firstPos == string::npos)
        return false;
    if (secondPos == string::npos)
        return true;

    return first.compare(firstPos + 1, 3, second, secondPos + 1, 3) >= 0;
}
