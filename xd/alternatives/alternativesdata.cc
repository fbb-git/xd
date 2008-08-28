#include "alternatives.ih"

char const *Alternatives::s_triState[] = 
{
    "false",
    "ifEmpty",
    "true"
};

char const **Alternatives::s_triStateEnd = 
        s_triState + sizeof(s_triState) / sizeof(char *);

