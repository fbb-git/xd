#include "history.ih"

void History::load(string const &homeDir)
{
    if (d_arg.option(&d_name, "history") && d_name.empty())
        d_name = homeDir + s_defaultHistory;

    ifstream in(d_name);
    if (!in)
    {
        imsg << "History file `" << d_name << "' not readable" << endl;
        return;
    }

    imsg << "History file `" << d_name << '\'' << endl;

    for_each(istream_iterator<HistoryInfo>(in), 
             istream_iterator<HistoryInfo>(),
             FnWrap::unary(maybeInsert, d_history, d_oldest));

    string value;

    size_t maxSize = 
        d_arg.option(&value, "history-maxsize") ?
            A2x(value)
        :
            UINT_MAX;

    if (maxSize != UINT_MAX)
        imsg << "Max. history size: " << maxSize << endl;

    if (d_history.size() > maxSize)
    {
        sort(d_history.begin(), d_history.end(), compareTimes);
        stable_sort(d_history.begin(), d_history.end(), compareCounts);

        d_history.resize(maxSize);
    }
}




