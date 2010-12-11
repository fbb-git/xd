#include "alternatives.ih"

string Alternatives::getHome() 
{
    string homeDir;

    char *cp = getenv("HOME");              // determine the homedir

    if (!cp)                                // save it
        homeDir = '/';
    else
    {
        homeDir = cp;
        if (*homeDir.rbegin() != '/')
            homeDir += '/';
    }
    // home set with ending /

    imsg << "Home directory: " << homeDir << endl;

    return homeDir;
}
