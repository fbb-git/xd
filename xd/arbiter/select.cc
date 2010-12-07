#include "arbiter.ih"

void Arbiter::select()
{
    if (d_alternatives.size() == 0)
        throw 0;                

    if (d_alternatives.size() == 1)
    {
        imsg << endl;
        d_index = 0;            // forced selection: one option
    }
    else
    {
        d_beginHistory = d_alternatives.beginHistory();
        d_endHistory = d_alternatives.endHistory();

        showAlternatives();
        setIndex();
    }

    cout << d_alternatives[d_index] << endl;
}





