#include "config.ih"

bool Config::searchPattern(string const &line, SearchContext &context)
try
{
    static Pattern pattern;

    pattern.setPattern(context.re, false);  // false: case insensitive match

    context.result->clear();
    pattern.match(line);
    *context.result = pattern[1];

    return true;
}
catch (...)
{
    return false;
}

