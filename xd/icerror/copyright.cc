/*                       I C C E C O P Y R I G H T . C C
*/

#include "icerror.h" 

void ICError::copyright(char const *function, char const *version,
        char const *years, int distribution)
{
    fprintf(stderr, "\n"
           "%s  Version %s\n"
           "Copyright (c) GPL %s. %s.\n"
           "\n",
           function, version, years,
           distribution ?
                "All rights reserved"
            :
                "Internal use only");
}
