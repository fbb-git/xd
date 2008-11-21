#include "command.ih"

void Command::concatArgs()
{
    ArgConfig &arg = ArgConfig::instance();

    for_each(arg.argPointers(), arg.argPointers() + arg.nArgs(), 
            FnWrap1c<char const *, string &>(catArg, d_arguments));
}
