#include "alternatives.ih"

void Alternatives::getCwd(unique_ptr<char> *dest)
{
    if (char *res = realpath(".", 0))
        dest->reset(res);
    else
    {
        fmsg << "Can't determine the current working dir." << endl;
        dest->reset(new char);
        dest[0] = 0;
    }
}

