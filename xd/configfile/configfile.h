#ifndef _ConfigFile_H_
#define _ConfigFile_H_

#include <stdio.h>
#include <string.h> 
#include "../icstring/icstring.h"

class ConfigFile: public ICString
{
    public:
    ConfigFile(char const *stream); // Name of config file given
    ~ConfigFile();          // destructor
    char const *get_param(      // gets a parameter (or 0)
            char const *name);
    char const *next_token(void);   // get the next token from wp
    private:
        void readfile(FILE *stream);    // Do the file reading
    char
        *wp;            // work copy of the string
};

#endif
