#include "alternatives.ih"

void Alternatives::setPopular()
{
    d_nPopular = 0;             // 0 popular alternatives encountered so far.

    string str;
    d_popularFirst = d_arg.option(&str, "popular-last") == 0;

    if (!d_arg.option(&d_popularityName, "popularity"))
        return;

    ifstream in(d_popularityName);
    if (!in)
    {
        imsg << "Popularity file `" << d_popularityName << 
                "' not readable" << endl;
        return;
    }

    copy(istream_iterator<StreamLine>(in), istream_iterator<StreamLine>(),
        back_inserter(d_popular));
}
