#include "alternatives.ih"

void Alternatives::updatePopular(size_t idx) const
{
    if (d_popularityName.empty())               // no popularity file in use
        return;

    string const &choice = (*this)[idx];

    if 
    (
        (d_popularFirst && idx >= d_nPopular)
        ||
        (not d_popularFirst && idx < size() - d_nPopular)
    )                                           // add a new choice to the
    {                                           // popular selections
        ofstream out(d_popularityName, ios::app);
        if (!out)
            imsg << "cannot write popularity file `" << d_popularityName << 
                                                            '\'' << endl;
        else
        {
            imsg << "added new choice `" << choice << "' to `" <<
                    d_popularityName << '\'' << endl;
            out << "1 " << choice << '\n';
        }
        return;
    }


    vector<string>::const_iterator iter = findPopular(choice);

    istringstream in(*iter);
    size_t count;
    in >> count;


    ofstream out(d_popularityName);
    if (!out)
    {
        imsg << "cannot write popularity file `" << d_popularityName << 
                                                        '\'' << endl;
        return;
    }

    copy(d_popular.begin(), iter, ostream_iterator<string>(out, "\n"));
    out << (count + 1) << ' ' << choice << '\n';
    copy(iter + 1, d_popular.end(), ostream_iterator<string>(out, "\n"));
}






