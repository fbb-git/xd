#include "alternatives.ih"

istream &operator>>(istream &in, Alternatives::HistoryInfo &hi)
{
    if (getline(in, hi.path))
    {
        istringstream ins(hi.path);
        if (not(ins >> hi.time >> hi.count  && getline(ins, hi.path)))
            hi.path.clear();
    }
    
    return in;
}
