#include "arbiter.ih"

Arbiter::Arbiter(Match const &match)
:
    d_match(match)
{
    if ((d_count = d_match.size()) == 0)
    {
        cerr << "No Solutions\n";
        d_number = 0;
        return;
    }

    if (d_count == 1)
    {
        d_number = 1;     // no choice: do what's selected
        return;
    }

    cerr << "Multiple Solutions:\n";

    for (size_t idx = 0; idx < d_match.size(); ++idx)
    {
        if (idx > 9 + 'z' - 'a')
        {
            cerr << "... (truncated)\n";
            break;              // won't display more...
        }

        cerr << setw(2);
        if (idx < 9)
            cerr << (idx + 1);
        else 
            cerr << static_cast<char>('a' - 10 + 1 + idx);
        cerr << ": " << d_match[idx] << endl;
    }
    
    select();
}

