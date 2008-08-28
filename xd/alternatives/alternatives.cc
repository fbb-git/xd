#include "alternatives.ih"

/*
    Options now:
    1. The pattern doesn't start with HOME: no extra search required
    Otherwise:
        2. extraparam == Config::single_search: no extra search
        else
        3. extraparam == Config::full_search:   extra search
        else
        4. extraparam == Config::double_search is implied.
           If now gl_pathc == 0, then do extra search

    So, extra search only if
    1. pattern doesn't start with $HOME
    and
        2. extraparam == full_search
        or
        3. extraparam == double_search
        and
        4. glob() didn't find anything.
*/

#include <algorithm>
#include <iterator>

Alternatives::Alternatives()
:
    d_ok(d_config)
{

    copy(d_command.begin(), d_command.end(), 
            ostream_iterator<string>(cout, "\n"));


                    // test conditions 1 and 2. If not,
                    // double search may be needed

//    register unsigned
//    home_length;
//
//    register Config::ConfigExtra
//    extraparam = cf.get_extraparam();
//
//    dirsparam = cf.get_dirsparam();
//    
//    if
//    (
//    !strncmp (pattern, cf.get_home(), home_length = strlen(cf.get_home()))
//    &&
//    (
//        extraparam == Config::full_search
//        ||
//        (
//        extraparam == Config::double_search
//        &&
//        !glob_struct.gl_pathc
//        )
//    )
//    )
//    glob(pattern + home_length - 1, 0, 0, &extra_glob); // no special flags,
//
//    id = 0;             // start with empty Id list
//    n = 0;              // no Id as yet
//
//    add_globbed(glob_struct);
//    add_globbed(extra_glob);
}








