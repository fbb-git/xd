#include "command.ih"

void Command::concatArgs(string *args)
{
    Arg &arg = Arg::instance();

    for_each(arg.argPointers(), arg.argPointers() + arg.nArgs(), 
            FnWrap1c<char const *, string &>(catArg, *args));

    args->resize(args->length() - 1);
}
