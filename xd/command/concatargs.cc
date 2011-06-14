#include "command.ih"

void Command::concatArgs()
{
    ArgConfig &arg = ArgConfig::instance();

    for_each(
        arg.argPointers(), arg.argPointers() + arg.nArgs(), 
        [&](char const *arg)
        {
            (d_arguments += arg) += '/';
        }
    );
}
