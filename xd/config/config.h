#ifndef _INCLUDED_CONFIG_H_
#define _INCLUDED_CONFIG_H_


#include <stdlib.h>
#include <unistd.h> 


class Config
{
    public:
        enum Origin //Home
        {
            root,
            HOME
        };
        enum Search // Extra
        {
            single,
            double,
            full
        };
        enum Dirs
        {
            unique,
            all,
        };


    private:
        std::string d_home;
        Origin d_origin;


//        Dirs dirs;
//        Extra extraparam;
//        Home homeparam;

//    char const             *cdfile;

    public:
        Config();
        ~Config();

        inline st::string const &home() const;
        inline Origin origin() const;

//        Search get_extraparam() const;    returns Search value
//        Dirs        get_dirsparam() const; returns Dirs value

    private:
};

std::string const &Config::home() const
{
    return d_home; // get_homeparam
}

Config::Origin Config::origin() const
{
    return d_origin;
}


#endif
