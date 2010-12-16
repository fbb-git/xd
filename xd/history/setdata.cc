#include "history.ih"

void History::setData()
{
    string value;

    d_position = 
        d_arg.option(&value, "history-position") && value == "bottom" ? 
            BOTTOM 
        : 
            TOP;

    imsg << "History elements at the " << 
                (d_position == TOP ? "top" : "bottom") << endl;

    if (not d_arg.option(&value, "history-lifetime"))
    {
        d_oldest = d_now - 24 * 60 * 60 * 30;       // 1 month lifetime
        imsg << "History lifetime: 1M" << endl;
        return;
    }

    A2x a2x(value);

    d_oldest = a2x;
    if (a2x.lastFail())
    {
        imsg << "Cannot determine history-lifetime " << value << 
                    ", using 1M" << endl;

        d_oldest = d_now - 24 * 60 * 60 * 30;       // 1 month lifetime
    }
    else
    {
        int lastChar = toupper(*value.rbegin());

        imsg << "History lifetime: " << d_oldest << 
                                        static_cast<char>(lastChar) << endl;
        d_oldest = d_now - d_oldest * 24 * 60 * 60 *
            (
                lastChar == 'W' ?   7 :
                lastChar == 'M' ?  30 :
                lastChar == 'Y' ? 365 : 1
            );
    }
}





