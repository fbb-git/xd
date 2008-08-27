/*                              xd.cc

   A C++ main()-frame generated by cpp.im for xd.cc

*/

#include "xd.ih"               // program header file


namespace   // the anonymous namespace can be used here
{
    Arg::LongOption longOptions[] =
    {
        Arg::LongOption("config-file", 'c'),
        Arg::LongOption("debug", 'd'),
        Arg::LongOption("help", 'h'),
        Arg::LongOption("version", 'v'),
        Arg::LongOption("verbose", 'V'),
    };

    Arg::LongOption const *const longEnd =
                    longOptions +
                    sizeof(longOptions) / sizeof(Arg::LongOption);
}

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("cdhvV",
                    longOptions, longEnd, argc, argv);

    arg.versionHelp(usage, Icmbuild::version, 1);

    Msg::setInfoBuf(cerr.rdbuf(), arg.option('d'));

    Config config;              // read the configuration

    Command
        command(config);      // build a command from args

    Match
        match(command.get_pattern(),    // make the matches
            config);

    Arbiter
        arbiter(match);         // Make the decision

    return command.write(arbiter.choice()) ? 0 : 1; // Write the cmd to file
}
catch(Errno const &err)     // handle exceptions
{
    cerr << err.what() << endl;
    return err.which();
}
catch(int x)
{
    return x;
}

