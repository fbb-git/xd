#include "configfile.h"

char const *ConfigFile::get_param(char const *name)
{
    char
        const *cp;
        
    for
    (
        register int index = 0;
            (cp = get_string(index));
                index++
    )
    {               // a string was obtained
        delete wp;      // remove old wp
        wp = strdup(cp);    // make a duplicate of the string

        if          // name is first token
        (
            !strcasecmp
            (
                strtok(wp, " \t\n"),
                name
            )
        )           // return the next token
            return (strtok(0, " \t\n"));
    }           
    delete wp;
    wp = 0;
    
    return (0);         // token not found      
}   
        
