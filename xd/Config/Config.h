#ifndef _Config_H_
#define _Config_H_

#include <stdlib.h>
#include <unistd.h> 
#include "../configfile/configfile.h"

#include "../configure.h" 

class Config
{
    public:
        enum ConfigHome
        {
                from_the_root,
                from_HOME
        };
        enum ConfigExtra
        {
                single_search,
                double_search,
                full_search
        };
        enum Dirs
        {
                unique,
                all,
        };
        Config();
        ~Config();
        char const *get_home(void) const;
        ConfigHome  get_homeparam(void) const;
        ConfigExtra get_extraparam(void) const;
        Dirs        get_dirsparam() const;
    private:
        Dirs
                dirs;
        ConfigExtra
                extraparam;
        ConfigHome
                homeparam;
        char
                *home,
                *cdfile;
};
#endif
