#include "arbiter.ih"

void Arbiter::showAlternatives() const
{
    imsg << endl;

    size_t begin = show(0, '1', '9');

    begin = show(begin, '0', '0');
    begin = show(begin, 'a', 'z');
    begin = show(begin, 'A', 'Z');
}





