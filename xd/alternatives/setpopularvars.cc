#include "alternatives.ih"

void Alternatives::setPopularVars()     // from viable()
{
    if (d_popularFirst)
        d_endPopular = d_nPopular;
    else
    {
        d_beginPopular = size() - d_nPopular;
        d_endPopular = size();
    }

    d_separateAt = 
                d_separateAt ?
                    d_popularFirst ? d_endPopular : d_beginPopular
            :
                UINT_MAX;

    cerr << d_popularFirst << ' ' << 
        d_beginPopular << ' '  << d_endPopular << ' ' <<d_separateAt << endl;
}
