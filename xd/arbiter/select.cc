#include "arbiter.ih"

void Arbiter::select()
{
    OneKey oneKey; // nckbd;
    register size_t c;

    c = oneKey.get();           // get the replay

    d_number = 
        '0' <= c && c <= '9' ?
        c  - '0'            // numbers < 10
        :
        c - ('a' - 10);         // numbers above 10

    if (d_number > d_count)         // none selected
        d_number = 0;
}
