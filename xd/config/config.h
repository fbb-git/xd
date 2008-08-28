#ifndef _INCLUDED_CONFIG_H_
#define _INCLUDED_CONFIG_H_

#include <bobcat/configfile>

class Config: public FBB::ConfigFile
{
    std::string d_configName;

    std::string d_home;         // /-terminated name of the homedir
    bool d_ok;                  // config file available (true) or not
    std::string d_searchResult;

    static char s_defaultConfig[];

    public:
        Config();

        std::string const &search(char const *key);
        
        inline std::string const &homeDir() const;
        inline operator bool() const;
    private:
        struct SearchContext
        {
            std::string re;
            std::string *result;
        };
        static bool searchPattern(std::string const &line, 
                                            SearchContext &context);

};


std::string const &Config::homeDir() const  
{
    return d_home; // get_homeparam
}

Config::operator bool() const
{
    return d_ok;
}

//Config::Origin Config::origin() const
//{
//    return d_origin;
//}


//        enum Origin //Home
//        {
//            ROOT,
//            HOME
//        };
//        enum Search // Extra
//        {
//            ORIGIN,
//            MAYBE_ROOT,
//            ALWAYS_ROOT
//        };
//        enum Dirs
//        {
//            UNIQUE,
//            ALL
//        };


//        std::string d_start;    // home, root, current?
//        Origin d_origin;


//        Dirs dirs;
//        Extra extraparam;
//        Home homeparam;

//    char const             *cdfile;


//        inline std::string const &homeDir() const;  // with final '/'
//        inline Origin origin() const;

//        Search get_extraparam() const;    returns Search value
//        Dirs        get_dirsparam() const; returns Dirs value

#endif

