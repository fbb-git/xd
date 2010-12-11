#include "history.ih"

void History::setData()
{
    string value;

    d_separator = d_arg.option(&value, "history-separate") && 
                  value == "bottom" ? 
                        BOTTOM 
                    : 
                        TOP;

    if (not d_arg.option(&value, "history-lifetime"))
    {
        d_lifetime = UINT_MAX;
        return;
    }

    A2x a2x(value);

    d_lifetime = a2x;
    if (a2x.lastFail())
    {
        imsg << "Cannot determine history-lifetime " << value << endl;
        d_lifetime = UINT_MAX;
    }
    else
    {
        int lastChar = toupper(*value.rbegin());

        d_lifetime *= d_now - 24 * 60 * 60 *
            (
                lastChar == 'W' ?   7 :
                lastChar == 'M' ?  30 :
                lastChar == 'Y' ? 365 : 1
            );
    }
}
