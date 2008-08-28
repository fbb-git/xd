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

    public:
        Alternatives();
        inline operator bool() const;
};

Alternatives::operator bool() const
{
    return d_ok;
}

#endif

