#include "arbiter.ih"

void Arbiter::select()
{
    if (d_alternatives.size() == 0)
        throw 0;                

    if (d_alternatives.size() == 1)
    {
        msg() << info;
        d_index = 0;            // forced selection: one option
    }
    else
    {
        showAlternatives();
        setIndex();
    }

    cout << d_alternatives[d_index] << endl;
}





