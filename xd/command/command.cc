#include "command.ih"

Command::Command()
:
    d_action(FROM_HOME),
    d_parent(0)
{
    string arguments;

    concatArgs(&arguments);

    bool subSpecs = determineAction(arguments);

    String::split(this, arguments, "/-");
    if (not subSpecs and Arg::instance().nArgs() == 1)
    {
        for_each(front().begin() + 1, front().end(), 
            FnWrap1c<char, vector<string> &>(add, *this));
        front().resize(1);
    }
}

