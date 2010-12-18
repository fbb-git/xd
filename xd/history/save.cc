#include "history.ih"

void History::save(string const &choice)
{
    if (d_name.empty())               // no history file in use
        return;

    ofstream out(d_name);
    if (!out)
    {
        imsg << "cannot write history file `" << d_name << '\'' << endl;
        return;
    }

    auto iter = findIter(choice);

    if (iter == d_history.end())
        d_history.push_back(HistoryInfo(d_now, 1, choice));
    else
        ++const_cast<HistoryInfo *>(&*iter)->count;

    sort(d_history.begin(), d_history.end(), compareTimes);
    stable_sort(d_history.begin(), d_history.end(), compareCounts);

    string value;

    size_t maxSize = d_arg.option(&value, "history-maxsize") ?
                        A2x(value)
                    :
                        UINT_MAX;

    if (maxSize != UINT_MAX)
        imsg << "Max. history size: " << maxSize << endl;

    if (d_history.size() > maxSize)
        d_history.resize(maxSize);
    
    copy(d_history.begin(), d_history.end(), 
                                ostream_iterator<HistoryInfo>(out, "\n"));
}






