#include "history.ih"

void History::save(size_t idx, string const &choice) const
{
    if (d_name.empty())               // no history file in use
        return;

//    if                                      // add a new choice to the
//    (                                       // history selections
//        (d_historySep == TOP  && d_separateAt <= idx)
//        ||
//        (d_historySep == BOTTOM && idx < d_separateAt)
//    )                                           
    {                                           
        ofstream out(d_name, ios::app);
        if (!out)
            imsg << "cannot write history file `" << d_name << '\'' << endl;
        else
        {
            imsg << "added new choice `" << choice << "' to `" <<
                    d_name << '\'' << endl;
            out << d_now << " 1 " << choice << '\n';
        }
        return;
    }

    auto iter = findHistory(choice);

    ofstream out(d_name);
    if (!out)
    {
        imsg << "cannot write history file `" << d_name << '\'' << 
                                                                        endl;
        return;
    }

    copy(d_history.begin(), iter, ostream_iterator<HistoryInfo>(out, "\n"));
    out << d_now << ' ' << (iter->count + 1) << ' ' << iter->path << '\n';
    copy(iter + 1, d_history.end(), ostream_iterator<HistoryInfo>(out, "\n"));
}






