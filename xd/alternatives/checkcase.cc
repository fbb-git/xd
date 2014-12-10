#include "alternatives.ih"

void Alternatives::checkCase(string &head, size_t *idx) const
{
    if ((d_arg.option('i') & 1) != 0)   // even number of --icase specs
    {
        string mold("[..]");
        int ch = head[*idx];
        if (isalpha(ch))
        {
            mold[1] = tolower(ch);
            mold[2] = toupper(ch);
            head.replace(*idx, 1, mold);
            *idx += 4;
            return;
        }
	}
    ++*idx;
}
