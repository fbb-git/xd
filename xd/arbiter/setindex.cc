#include "arbiter.ih"

void Arbiter::setIndex()
{
    OneKey oneKey;
    int c;

    c = oneKey.get();           // get the replay

    if (isdigit(c))
        d_index = c - '0';
    else if (islower(c))
        d_index = '9' - '0' + 1 +  c - 'a';
    else if (isupper(c))
        d_index = '9' - '0' + 1 + 'z' - 'a' + 1 + c - 'A';
    else
        throw 1;
}





