#ifndef _Arbiter_H_
#define _Arbiter_H_

#include <stdio.h> 
#include <stdlib.h>
#include "../noncanon/noncanon.h"

#include "../Match/Match.h"

class Arbiter
{
    public:
        Arbiter(Match const &match);
        char const *get_choice(void);
    private:
        void select(void);
        
        unsigned
                count,
                number;
        Match const
                *match;
        
};
#endif
