#include "alternatives.ih"

void Alternatives::setHome() 
{
    char *cp = getenv("HOME");              // determine the homedir

    if (!cp)                                // save it
        d_homeDir = '/';
    else
    {
        d_homeDir = cp;
        if (*d_homeDir.rbegin() != '/')
            d_homeDir += '/';
    }
    // home set with ending /

    msg() << "Home directory: " << d_homeDir << info;
}
