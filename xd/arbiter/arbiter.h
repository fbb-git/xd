#ifndef _Arbiter_H_
#define _Arbiter_H_

#include <string>

#include "../alternatives/alternatives.h"

class Arbiter
{
    size_t d_index;
    size_t d_beginPopular;      // set in showAlternatives
    size_t d_endPopular;
    Alternatives const &d_alternatives;
            
    public:
        Arbiter(Alternatives const &alternatives);

        void select();
        bool decided() const;

    private:
        void showAlternatives() const;
        size_t show(size_t begin, char first, char last) const;
        void setIndex();
};

#endif
