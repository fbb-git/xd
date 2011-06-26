#include "arbiter.ih"

void Arbiter::showAlternatives() const
{
    imsg << endl;

    size_t separateAt = d_alternatives.separateAt();

    size_t begin = show(0, '1', '9', separateAt);

    begin = show(begin, '0', '0', separateAt);
    begin = show(begin, 'a', 'z', separateAt);
    begin = show(begin, 'A', 'Z', separateAt);
}





