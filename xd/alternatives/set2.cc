#include "alternatives.ih"

size_t Alternatives::set(char const *key, 
                            char const **begin, char const **end, 
                            size_t notFound)
{
    string conf = d_config.search(key);

    char const **ret = 
        find_if(begin, end, 
                not1(FnWrap1c<string const &, string const &, int>
                                (String::casecmp, conf)));

    return ret == end ? notFound : ret - begin;
}
