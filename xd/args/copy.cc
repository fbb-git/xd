#include "args.h"

void Args::copy(char const *str)
{
    char
    *cp;
    
    if ((cp = strrchr(str, '/')))
        str = cp + 1;
    
    prog = strdup(str);
}

