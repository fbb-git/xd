#include "config.ih"

static char XD_CONF_PATH[] = ".xdrc";

Config::Config()
{
    char
    buffer[512];

    if (!(home = getenv("HOME")))       // HOME not found
    home = strdup("/");         // use root's HOME
    else
    {
    strcpy(buffer, home);
    strcat(buffer, "/");            // append / to home
    home = strdup(buffer);          // local home copy
    }
                        // Make first estimate
    strcat(strcpy(buffer, home), XD_CONF_PATH); // of config file

    if (access(buffer, R_OK))           // can't read the file
    strcpy(buffer, XD_CONF_PATH);       // use default file
        
//                     // Read the file
//    ConfigFile cf(buffer, ConfigFile::RemoveComment, 
//                          ConfigFile::SearchCaseInsensitive);
//    
//    ConfigFile::const_iterator iter = cf.find("HOME");

    homeparam = from_the_root;
    
//    homeparam =
//        iter != cf.end() && iter->find("true") ?
//            from_the_root           // use from the root
//        :
//            from_HOME;              // otherwise from HOME.

    if (homeparam == from_HOME)         // search from HOME
    {
        extraparam = double_search;     // assume by default double search

//      if ((token = cf.get_param("EXTRA")))  // 'extra' parameter found ?
//      {
//          if (!strcasecmp(token, "no"))    // If the user requests 'no'
//          extraparam = single_search;  // use single search
//          else if (!strcasecmp(token, "always"))   // it's 'always' ?
//          extraparam = full_search;        // use allways full search
//      }
    }
    else
        extraparam = single_search;     // single search if not from HOME

    dirs = unique;
//    (token = cf.get_param("DIRECTORIES")) // directories parameter found ?
//    &&
//    !strcasecmp(token, "all") ?     // and it's all
//        all                 // then use 'all'
//    :
//        unique;             // otherwise use unique
}








