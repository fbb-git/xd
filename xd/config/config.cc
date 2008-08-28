#include "config.ih"

Config::Config()
:
    ConfigFile(ConfigFile::RemoveComment, ConfigFile::SearchCaseInsensitive),
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
    
    
        string configName;
    
        if (arg.option(&configName, 'c'))
            open(configName);
        else 
        {
            configName = d_home + s_defaultConfig;
            Stat confStat(configName);
            if (confStat)
            {
                if (not confStat.mode() & Stat::UR)
                    msg() << "Can't read " << configName << warning;
                else
                    open(configName);
            }
        }
    
        
    //    homeparam =
    //        iter != cf.end() && iter->find("true") ?
    //            from_the_root           // use from the root
    //        :
    //            from_HOME;              // otherwise from HOME.
    
    //    if (homeparam == from_HOME)         // search from HOME
    //    {
    //        extraparam = double_search;     // assume by default double search
    
    //      if ((token = cf.get_param("EXTRA")))  // 'extra' parameter found ?
    //      {
    //          if (!strcasecmp(token, "no"))    // If the user requests 'no'
    //          extraparam = single_search;  // use single search
    //          else if (!strcasecmp(token, "always"))   // it's 'always' ?
    //          extraparam = full_search;        // use allways full search
    //      }
    //    }
    //    else
    //        extraparam = single_search;     // single search if not from HOME
    
    //    dirs = unique;
    //    (token = cf.get_param("DIRECTORIES")) // directories parameter found ?
    //    &&
    //    !strcasecmp(token, "all") ?     // and it's all
    //        all                 // then use 'all'
    //    :
    //        unique;             // otherwise use unique
    }
    catch (Errno const &err)
    {
        cerr << err.what() << endl;
        d_ok = false;
    }
}






