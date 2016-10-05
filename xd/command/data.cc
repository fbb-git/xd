#include "command.ih"

char const *Command::s_action[] = 
{
    "FROM_CONFIG",
    "FROM_HOME",
    "FROM_ROOT",
    "FROM_CWD",
    "FROM_PARENT"
};

                                    // separating parts of directory names:
char const Command::s_separators[] = "/";     
