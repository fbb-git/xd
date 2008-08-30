#include "alternatives.ih"


void Alternatives::addIgnored(string const &line, std::set<string> &ignoreSet)
{
    istringstream in(line);
    string path;
    in >> path >> path;         // skip ignore, extract path

    path.resize(path.length() - 1);
    msg() << "ignoring " << path << info;

    ignoreSet.insert(path);
}
