#include "arbiter.ih"

void Arbiter::setIndex()
{
    int c;
    OneKey oneKey;

    oneKey.verify();

    c = oneKey.get();           // get the replay

    if (c == '0')
        d_index = 9;
    else if (isdigit(c))
        d_index = c - '1';
    else if (islower(c))
        d_index = '9' - '0' + 1 +  c - 'a';
    else if (isupper(c))
        d_index = '9' - '0' + 1 + 'z' - 'a' + 1 + c - 'A';
    else
        throw 1;

    if (d_index > d_alternatives.size())
        throw 1;
}





