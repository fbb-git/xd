#include "arbiter.ih" 

std::string const &Arbiter::choice() const
{
    static string dot(".");

    return d_number ? d_match[d_number - 1] : dot;
}   
