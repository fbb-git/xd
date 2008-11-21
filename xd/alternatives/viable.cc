#include "alternatives.ih"

void Alternatives::viable()
{
    if (!d_ok)
        throw 1;                    // terminate the program 

    d_home = set(0, "start-at", s_startAt, s_startAtEnd, 1);
    d_dirs = set(0, "directories", s_dirs, s_dirsEnd, 1);
    d_addRoot = static_cast<TriState>
                  (set(0, "add-root", s_triState, s_triStateEnd, IF_EMPTY));
    
    msg() << boolalpha  << "Search from $HOME: " << d_home << '\n' <<
                "Search all directories: " << d_dirs << '\n' <<
                "Add root search if search from  $HOME fails: " <<
                                            s_triState[d_addRoot] << info;
    globFrom(determineInitialDirectory());
    sort(begin(), end());
}
