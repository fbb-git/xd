#include "alternatives.ih"

void Alternatives::getCwd(auto_ptr<char> *dest)
{
    dest->reset(new char[PATH_MAX]);

    if (not realpath(".", dest->get()))
        msg() << "Can't determine the current working dir." << fatal;
}
