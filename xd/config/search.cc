#include "config.ih"

std::string const &Config::search(char const *key)
{
    SearchContext context = {"^\\s*", &d_searchResult};
    context.re += key;
    context.re += "\\s+(\\w+)\\s*$";

    vector<string>::const_reverse_iterator begin = rbegin();
    vector<string>::const_reverse_iterator end = rend();

    find_if(begin, end, FnWrap1c<string const &, SearchContext &, bool>
                                   (searchPattern, context));

    if (Arg::instance().option('d'))
    {
        cerr << "Matching " << context.re << " in " << d_configName << 
                " finds `" << d_searchResult << "'\n";
    }

    return d_searchResult;
}
