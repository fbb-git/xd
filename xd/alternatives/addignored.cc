#include "alternatives.ih"


void Alternatives::addIgnored(string const &line, std::set<string> &ignoreSet)
{
    istringstream in(line);
    string path;
    in >> path >> path;         // skip ignore, extract path

                                // add a / unless the path ends in * or / 
    if (*path.rbegin() != '*' && *path.rbegin() != '/')
        path += '/';

    imsg << "ignoring " << path << endl;

    ignoreSet.insert(path);
}
