#ifndef _Command_H_
#   define _Command_H_

#include <malloc.h>

#include "../args/args.h"
#include "../Config/Config.h" 

class Command
{
    public:
        Command(Args const &args,       // Constructor
                Config const &cf);      
        ~Command();                     // Destructor (2)
        char const *get_pattern();      // Request the pattern 0 if saw_eq.
        int write(char const *path);    // Write the selected path
    private:
        void separated_pattern(char *); // set up separated pattern
                                        // e.g., from xd ho fr t
        void one_pattern(char *);       // set up single pattern
                                        // e.g. from xd hft

        Config
                const *config;
        char
                *command,               // command received
                *pattern;               // pattern built
};

#   endif
