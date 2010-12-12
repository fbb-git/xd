#include "history.ih"

void History::save(string const &choice) const
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

    copy(d_history.begin(), iter, ostream_iterator<HistoryInfo>(out, "\n"));

    if (iter == d_history.end()) 
        out << d_now << " 1 " << choice << '\n';
    else
    {
        out << d_now << ' ' << (iter->count + 1) << ' ' << choice << '\n';
        copy(iter + 1, d_history.end(),
                                    ostream_iterator<HistoryInfo>(out, "\n"));
    }
}






