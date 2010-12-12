#include "history.ih"

void History::setData()
{
    string value;

    d_position = 
        d_arg.option(&value, "history-position") && value == "bottom" ? 
            BOTTOM 
        : 
            TOP;

    if (not d_arg.option(&value, "history-lifetime"))
    {
        d_oldest = d_now - 24 * 60 * 60 * 30;       // 1 month lifetime
        return;
    }

    A2x a2x(value);

    d_oldest = a2x;
    if (a2x.lastFail())
    {
        imsg << "Cannot determine history-lifetime " << value << endl;
        d_oldest = d_now - 24 * 60 * 60 * 30;       // 1 month lifetime
    }
    else
    {
        int lastChar = toupper(*value.rbegin());

        d_oldest = d_now - 24 * 60 * 60 *
            (
                lastChar == 'W' ?   7 :
                lastChar == 'M' ?  30 :
                lastChar == 'Y' ? 365 : 1
            );
    }
}





