#include "xd.ih"               // program header file

namespace   // the anonymous namespace can be used here
{
    ArgConfig::LongOption longOptions[] =
    {
        ArgConfig::LongOption("add-root",     ArgConfig::Required),
        ArgConfig::LongOption("directories",  ArgConfig::Required),
        ArgConfig::LongOption("start-at",     ArgConfig::Required),
        ArgConfig::LongOption("traditional"),

        ArgConfig::LongOption("all",                'a'),
        ArgConfig::LongOption("config-file",        'c'),
        ArgConfig::LongOption("help",               'h'),
        ArgConfig::LongOption("generalized-search", 'g'),
        ArgConfig::LongOption("version",            'v'),
        ArgConfig::LongOption("verbose",            'V'),
    };

    ArgConfig::LongOption const *const longEnd =
                    longOptions +
                    sizeof(longOptions) / sizeof(ArgConfig::LongOption);
}

void arguments(int argc, char **argv)
{
    ArgConfig &arg = ArgConfig::initialize("ac:ghvV",
                        longOptions, longEnd, argc, argv);
    arg.setCommentHandling(ArgConfig::RemoveComment);

    arg.versionHelp(usage, Icmbuild::version, 1);

    if (arg.option('V'))
        imsg.reset(cerr);
    else
        imsg.off();

    fmsg.reset(cerr);
}


