#include "alternatives.ih"

void Alternatives::setHistoryVars()     // from viable()
{
    switch (d_historySep)
    {
        case TOP:
            d_endHistory = d_nHistory;
            d_separateAt = d_endHistory;
        break;
        case BOTTOM:
            d_beginHistory = size() - d_nHistory;
            d_endHistory = size();
            d_separateAt = d_beginHistory;
        break;
        case DONT:
            d_separateAt = UINT_MAX;
        break;
    }
}
