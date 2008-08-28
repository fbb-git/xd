#include "alternatives.ih"

bool Alternatives::set(char const *key)
{
    string conf = d_config.search(key);

    return conf.length() == 0 || String::casecmp(conf, "true") == 0;
}
