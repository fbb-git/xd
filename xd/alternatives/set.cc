#include "alternatives.ih"

bool Alternatives::set(char const *key, char const *trueText)
{
    string conf = d_config.search(key);

    return conf.length() == 0 || String::casecmp(conf, trueText) == 0;
}
