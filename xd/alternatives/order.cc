#include "alternatives.ih"

void Alternatives::order()
{
    if (d_popularityName.empty() || d_nPopular == 0 || d_popularFirst)
        return;

    rotate(begin(), begin() + d_nPopular, end());
}
