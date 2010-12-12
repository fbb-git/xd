#include "alternatives.ih"

void Alternatives::viable()
{
    d_home = set("start-at", s_startAt, s_startAtEnd, 1);
    d_dirs = set("directories", s_dirs, s_dirsEnd, 1);
    d_addRoot = static_cast<TriState>
                  (set("add-root", s_triState, s_triStateEnd, IF_EMPTY));
    
    imsg << boolalpha  << "Search from $HOME: " << d_home << '\n' <<
                "Search all directories: " << d_dirs << '\n' <<
                "Add root search if search from  $HOME fails: " <<
                                            s_triState[d_addRoot] << endl;

    globFrom(determineInitialDirectory());

    sort(begin(), begin() + d_nInHistory);
    sort(begin() + d_nInHistory, end());
}
