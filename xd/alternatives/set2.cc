#include "alternatives.ih"

size_t Alternatives::set(char const *key, 
                            char const **begin, char const **end, 
                            size_t notFound)
{
    string conf;

    if (!d_arg.option(&conf, key))
         d_config.search(key);

    if (conf.length() == 0)
    {
        if (d_debug)
            cerr << "Option or config: No key " << key << endl;
        return notFound;
    }

    char const **ret = 
        find_if(begin, end, bind2nd(equal_to<string>(), conf));

    if (ret != end)
    {
        if (d_debug)
            cerr << "Option or config `" << key << " " << conf << "' found\n";
        return ret - begin;
    }

    msg() << "`" << key << " " << conf << 
            "' not supported. Using the default `" << begin[notFound] <<
            "'." << info;

    return notFound;
}






