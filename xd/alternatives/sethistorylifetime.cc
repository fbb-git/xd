#include "alternatives.ih"

void Alternatives::setHistoryLifetime()
{
    string value;

    if (not d_arg.option(&value, "history-lifetime"))
    {
        d_historyLifetime = UINT_MAX;
        return;
    }

    A2x a2x(value);

    d_historyLifetime = a2x;
    if (a2x.lastFail())
    {
        imsg << "Cannot determine history-lifetime " << value << endl;
        d_historyLifetime = UINT_MAX;
    }
    else
    {
        int lastChar = toupper(*value.rbegin());

        d_historyLifetime *= d_now - 24 * 60 * 60 *
            (
                lastChar == 'W' ? 7 :
                lastChar == 'M' ? 30 :
                lastChar == 'Y' ? 365
            );
    }
}
