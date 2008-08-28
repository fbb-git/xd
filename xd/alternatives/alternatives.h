#ifndef _INCLUDED_ALTERNATIVES_H_
#define _INCLUDED_ALTERNATIVES_H_

#include <vector>
#include <string>

#include "../config/config.h"
#include "../command/command.h"

class Alternatives: public std::vector<std::string>
{
    Config d_config;
    bool d_ok;

    Command d_command;

//            dirsparam;
//    glob_t
//            glob_struct,
//            extra_glob;             // used for the extra search
//    unsigned
//        n;
//    Id                              // file ID
//        *id;
    public:
        Alternatives();
        inline operator bool() const;

//    private:
//        struct Id
//        {
//            ino_t
//                inode;
//            dev_t
//                device;
//        };
//        void add_globbed                // add globbed patterns
//            (const glob_t &glob_struct);
//        int lookup(ino_t inode,         // look up file id info
//                    dev_t device) const;
};

Alternatives::operator bool() const
{
    return d_ok;
}

#endif

