#include "alternatives.ih"

void Alternatives::setHistory()
{
    string value;

    d_historySep = not d_arg.option(&value, "history-separate") ?
                        DONT
                    :
                        value == "bottom" ? BOTTOM : TOP;

    if (!d_arg.option(&d_historyName, "history"))
        d_historyName = d_homeDir + s_defaultHistory;

    ifstream in(d_historyName);
    if (!in)
    {
        imsg << "History file `" << d_historyName << "' not readable" << endl;
        return;
    }

    for_each(istream_iterator<HistoryLine>(in), 
             istream_iterator<HistoryLine>(),
             FnWrap::unary(maybeInsert(d_history, d_now));

    if (d_history.size() > d_maxHistorySize)
        partial_sort(d_history.begin(), d_history.begin() + d_maxHistorySize, 
                d_history.end(), compareGreater);
}






