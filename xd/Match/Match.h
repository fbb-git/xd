#ifndef _Match_H_
#   define _Match_H_

#include <glob.h>
#include <sys/stat.h>
#include <unistd.h> 
#include "../icstring/icstring.h"

#include "../Config/Config.h"

class Match: public ICString
{
    public:
        Match(const char *pattern,      // Constructor
            Config const &cf);  
        ~Match();                       // Destructor (2)
    private:
        struct Id
        {
            ino_t
                inode;
            dev_t
                device;
        };
        void add_globbed                // add globbed patterns
            (const glob_t &glob_struct);
        int lookup(ino_t inode,         // look up file id info
                    dev_t device) const;

        Config::Dirs
                dirsparam;
        glob_t
                glob_struct,
                extra_glob;             // used for the extra search
        unsigned
            n;
        Id                              // file ID
            *id;
};

#   endif
