#include "xd.ih"               // program header file

namespace   // the anonymous namespace can be used here
{
    ArgConfig::LongOption longOptions[] =
    {
        {"add-root",     ArgConfig::Required},
        {"directories",  ArgConfig::Required},
        {"start-at",     ArgConfig::Required},
        {"popularity",   ArgConfig::Required},

        {"popular-last",        ArgConfig::None},
        {"popular-separate",    ArgConfig::None},
        {"traditional",         ArgConfig::None},

        {"all",                'a'},
        {"config-file",        'c'},
        {"help",               'h'},
        {"generalized-search", 'g'},
        {"version",            'v'},
        {"verbose",            'V'},
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

    imsg.setActive(arg.option('V'));

    fmsg.reset(cerr);
}


