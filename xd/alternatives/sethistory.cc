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

    for_each(istream_iterator<HistoryInfo>(in), 
             istream_iterator<HistoryInfo>(),
             FnWrap::unary(maybeInsert, d_history, d_now - d_historyLifetime));

    size_t maxSize = 
        d_arg.option(&value, "history-maxsize") ?
            A2x(value)
        :
            UINT_MAX;

    if (d_history.size() > maxSize)
    {
        partial_sort(d_history.begin(), d_history.begin() + maxSize, 
                d_history.end(), compareGreater);
        d_history.resize(d_nHistory = maxSize);
    }
}






