#include "history.ih"

istream &operator>>(istream &in, History::HistoryInfo &hi)
{
    if (getline(in, hi.path))
    {
        istringstream ins(hi.path);

        if (ins >> hi.time >> hi.count  && getline(ins, hi.path))
            hi.path = String::trim(hi.path);
        else
            hi.path.clear();
    }
    
    return in;
}
