/*
                                A R G L I S T . H
*/

#ifndef __Args_H_
#define __Args_H_

#include "../icstring/icstring.h"

class Args: public ICString
{
    public:
    Args                    // constructor
        (unsigned argc, char const *const *argv);
    ~Args();                // destructor (2)
    Args(const Args &other);        // copy constructor (3)
                        // assign (overloaded)
    const Args &operator = (const Args &other);

    char const *get_progname(void) const;
    
    private:
    void copy(char const *str);     // internal copy function
    void destroy(void);         // insternal destructor

    char
        *prog;              // name of the program
};

#endif

