#include "alternatives.ih"

void Alternatives::viable()
{
    if (!d_ok)
        throw 1;                    // terminate the program 

    d_home = set("home", "true");
    d_dirs = set("directories", "all");

    d_addRoot = static_cast<TriState>
                    (set("addRoot", s_triState, s_triStateEnd, IF_EMPTY));

    if (Arg::instance().option('d'))
    {
        cerr << boolalpha  << "Search from $HOME: " << d_home << '\n' <<
                "Search all directories: " << d_dirs << '\n' <<
                "Add root search if search from  $HOME fails: " <<
                                            s_triState[d_addRoot] << endl;
    }

    globFrom(determineInitialDirectory());

    sort(begin(), end());
}
