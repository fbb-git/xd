#include "icstring.h"

void ICString::copy(unsigned cnt, char const *const *vec)
{
    count = cnt;
    vector = new char * [count];    // new vector;

                    // duplicate of other vector
    for (register unsigned i = 0; i < count; i++)
        vector[i] = strdup(vec[i]);
}
