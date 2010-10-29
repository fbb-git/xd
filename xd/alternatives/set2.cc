#include "alternatives.ih"

size_t Alternatives::set(char const *longKey, 
                         char const *const *const begin, 
                         char const *const *const end, 
                         size_t notFound)
{
    string conf;

    if (!d_arg.option(&conf, longKey))
    {
        imsg << "Option or config: No key " << longKey << endl;
        return notFound;
    }

    char const *const *const ret = 
                    find_if(begin, end, bind2nd(equal_to<string>(), conf));

    if (ret != end)
    {
        imsg << "Option or config `" << longKey << " " << conf << "' found" <<
                endl;

        return ret - begin;
    }

    imsg << "`" << longKey << " " << conf << 
            "' not supported. Using the default `" << begin[notFound] <<
            "'." << endl;

    return notFound;
}






