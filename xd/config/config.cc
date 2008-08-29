#include "config.ih"

Config::Config()
:
    ConfigFile(ConfigFile::RemoveComment),
    d_ok(true)
{
    try
    {
        Arg &arg = Arg::instance();
    
        char *cp = getenv("HOME");              // determine the homedir
    
        if (!cp)                                // save it
            d_home = '/';
        else
        {
            d_home = cp;
            if (*d_home.rbegin() != '/')
                d_home += '/';
        }
        // home set with ending /

        msg() << "Home directory: " << d_home << info;
    
    
        if (arg.option(&d_configName, 'c'))
            open(d_configName);
        else 
        {
            d_configName = d_home + s_defaultConfig;
            Stat confStat(d_configName);
            if (confStat)
            {
                if (not confStat.mode() & Stat::UR)
                    msg() << "Can't read " << d_configName << warning;
                else
                    open(d_configName);
            }
        }
        msg() << "Configuration file: " << d_configName << info;
    }
    catch (Errno const &err)
    {
        cerr << err.what() << endl;
        d_ok = false;
    }
}






