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

    for_each(
        istream_iterator<HistoryInfo>(in), 
        istream_iterator<HistoryInfo>(),
        [&](HistoryInfo  const &historyInfo)
        {
            maybeInsert(historyInfo, d_history, d_oldest);
        }
    );
}



