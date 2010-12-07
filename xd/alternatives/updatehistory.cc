#include "alternatives.ih"

void Alternatives::updateHistory(size_t idx) const
{
    if (d_historyName.empty())               // no history file in use
        return;

    string const &choice = (*this)[idx];

    if 
    (
        (d_historyFirst && idx >= d_nHistory)
        ||
        (not d_historyFirst && idx < size() - d_nHistory)
    )                                           // add a new choice to the
    {                                           // history selections
        ofstream out(d_historyName, ios::app);
        if (!out)
            imsg << "cannot write history file `" << d_historyName << 
                                                            '\'' << endl;
        else
        {
            imsg << "added new choice `" << choice << "' to `" <<
                    d_historyName << '\'' << endl;
            out << "1 " << choice << '\n';
        }
        return;
    }


    vector<string>::const_iterator iter = findHistory(choice);

    istringstream in(*iter);
    size_t count;
    in >> count;


    ofstream out(d_historyName);
    if (!out)
    {
        imsg << "cannot write history file `" << d_historyName << 
                                                        '\'' << endl;
        return;
    }

    copy(d_history.begin(), iter, ostream_iterator<string>(out, "\n"));
    out << (count + 1) << ' ' << choice << '\n';
    copy(iter + 1, d_history.end(), ostream_iterator<string>(out, "\n"));
}






