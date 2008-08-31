#include "alternatives.ih"


void Alternatives::addIgnored(string const &line, std::set<string> &ignoreSet)
{
    istringstream in(line);
    string path;
    in >> path >> path;         // skip ignore, extract path

    if (*path.rbegin() == '/')  // keep the final * if it's there
        path.resize(path.length() - 1);

    msg() << "ignoring " << path << info;

    ignoreSet.insert(path);
}
