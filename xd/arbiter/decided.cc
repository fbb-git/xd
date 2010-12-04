#include "arbiter.ih"

bool Arbiter::decided() const
{
    d_alternatives.updatePopular(d_index);

    return d_index != d_alternatives.size();
}
