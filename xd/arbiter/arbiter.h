#ifndef _Arbiter_H_
#define _Arbiter_H_

#include <string>

#include "../Match/Match.h"

class Arbiter
{
    size_t d_count;
    size_t d_number;
    Match const &d_match;
        
    public:
        Arbiter(Match const &match);
        std::string const &choice() const;
    private:
        void select();
};
#endif
