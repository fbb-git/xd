#include "alternatives.ih"

char const *Alternatives::s_merge[] = 
{
    "false",
    "true"
};
char const *const *const Alternatives::s_mergeEnd = 
        s_triState + sizeof(s_merge) / sizeof(char *);


char const *Alternatives::s_triState[] = 
{
    "never",
    "if-empty",
    "always"
};

char const *const *const Alternatives::s_triStateEnd = 
        s_triState + sizeof(s_triState) / sizeof(char *);


char const *Alternatives::s_startAt[] = 
{
    "root",
    "home",
};

char const *const *const Alternatives::s_startAtEnd = 
        s_startAt + sizeof(s_startAt) / sizeof(char *);


char const *Alternatives::s_dirs[] = 
{
    "unique",
    "all",
};

char const *const *const Alternatives::s_dirsEnd = 
        s_dirs + sizeof(s_dirs) / sizeof(char *);


