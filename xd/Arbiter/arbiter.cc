#include "Arbiter.h"

Arbiter::Arbiter(Match const &mtch)
{
    if (!(count = mtch.get_count()))
    {
        fprintf(stderr, "No Solutions\n");
        number = 0;
        return;
    }

    match = &mtch;
    
    if (count == 1)
    {
        number = 1;     // no choice: do what's selected
        return;
    }

    fprintf(stderr, "Multiple Solutions:\n");

    register char
        const *cp;
        
    for (register unsigned idx = 0; (cp = match->get_string(idx)); )
    {
        if (++idx > 9 + 'z' - 'a' + 1)
        break;              // won't display more...
        
        fprintf(stderr, "%2c: %s\n",
            idx < 10 ?
            '0' + idx       // numbers up to 9
            :
            ('a' - 10 + idx),   // 'a'.. thereafter
            cp);
    }
    
    select();
}
