#include "alternatives.ih"

void Alternatives::updateHistory(size_t idx) const
{
    if (d_historyName.empty())               // no history file in use
        return;

    string const &choice = (*this)[idx];

    if                                      // add a new choice to the
    (                                       // history selections
        (d_historySep == TOP  && d_separateAt <= idx)
        ||
        (d_historySep == BOTTOM && idx < d_separateAt)
    )                                           
    {                                           
        ofstream out(d_historyName, ios::app);
        if (!out)
            imsg << "cannot write history file `" << d_historyName << 
                                                            '\'' << endl;
        else
        {
            imsg << "added new choice `" << choice << "' to `" <<
                    d_historyName << '\'' << endl;
            out << d_now << " 1 " << choice << '\n';
        }
        return;
    }

    auto iter = findHistory(choice);

    ofstream out(d_historyName);
    if (!out)
    {
        imsg << "cannot write history file `" << d_historyName << '\'' << 
                                                                        endl;
        return;
    }

    copy(d_history.begin(), iter, ostream_iterator<HistoryInfo>(out, "\n"));
    out << d_now << ' ' << (iter->count + 1) << ' ' << iter->path << '\n';
    copy(iter + 1, d_history.end(), ostream_iterator<HistoryInfo>(out, "\n"));
}






