#include "alternatives.ih"

bool Alternatives::matchIgnore(std::string const &ignore, char const *entry)
{
    return
        *ignore.rbegin() != '*' ?       // literal match required
            ignore == entry
        :                               // wildcard match of final * OK
            string(entry).find(ignore.substr(0, ignore.length() - 1)) == 0;
}
