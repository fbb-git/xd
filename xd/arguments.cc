#include "xd.ih"               // program header file

namespace   // the anonymous namespace can be used here
{
    ArgConfig::LongOption longOptions[] =
    {
        {"add-root",    ArgConfig::Required},
        {"directories", ArgConfig::Required},
        {"start-at",    ArgConfig::Required},

        {"history",             ArgConfig::Optional},
        {"history-lifetime",    ArgConfig::Required},
        {"history-maxsize",     ArgConfig::Required},   // history/load.cc
        {"history-separate",    ArgConfig::None},
        {"history-position",    ArgConfig::Required},   // top, bottom

        {"traditional",         ArgConfig::None},

        {"all",                'a'},
        {"config-file",        'c'},
        {"help",               'h'},
        {"icase",              'i'},
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
    char *last = argv[argc - 1];        // remove the / from the last
    size_t idx = strlen(last) - 1;      // cmd line argument
    if (last[idx] == '/')
        last[idx] = 0;
    
    ArgConfig &arg = ArgConfig::initialize("ac:gihvV",
                        longOptions, longEnd, argc, argv);
    arg.setCommentHandling(ArgConfig::RemoveComment);

    streambuf *buf = cout.rdbuf(cerr.rdbuf());      // make sure that
    try                                             // versionHelp doesn't
    {                                               // write to cout
        arg.versionHelp(usage, Icmbuild::version, 1);
        cout.rdbuf(buf);
    }
    catch(...)
    {
        cout.rdbuf(buf);
        throw;
    }
    
    imsg.reset(cerr);
    imsg.setActive(arg.option('V'));

    fmsg.reset(cerr);
}


