#ifndef _INCLUDED_COMMAND_H_
#define _INCLUDED_COMMAND_H_

#include <string>

#include "../Config/Config.h" 

class Command
{
    public:
        Command(
                Config const &cf);      
        ~Command();                     // Destructor (2)
        char const *get_pattern();      // Request the pattern 0 if saw_eq.
        bool write(std::string const &path) const; // Write the selected path
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

#endif
