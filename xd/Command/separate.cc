#include "Command.h"

void Command::separated_pattern(char *next)
{
    char
        *token;

    token = strtok(next, "/-");     // grab the first token

    do
    {
        strcat(pattern, token);     // append it
        strcat(pattern, "*/");      // append '*/'
    }
    while ((token = strtok(0, "/-")));
}

