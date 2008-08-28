#include "arbiter.ih"

void Arbiter::showAlternatives() const
{
    size_t begin = show(0, '0', '9');

    begin = show(begin, 'a', 'z');
    begin = show(begin, 'A', 'Z');
}





