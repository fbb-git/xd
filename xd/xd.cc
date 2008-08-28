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
    Arg &arg = Arg::initialize("c:dhvV",
                    longOptions, longEnd, argc, argv);

    arg.versionHelp(usage, Icmbuild::version, 1);
    Msg::setInfoBuf(cerr.rdbuf(), arg.option('d'));

    Alternatives alternatives;
    alternatives.viable();              // select viable alternatives

    Arbiter arbiter(alternatives);

    arbiter.select();                   // make the selection

    return arbiter.decided() ? 0 : 1;   // return 0 to the OS if the arbiter
                                        // did do its work 
}
catch(Errno const &err)     // handle exceptions
{
    cerr << err.what() << endl;
    cout << ".\n";          // to prevent a diretory change
    return err.which();
}
catch(int x)
{
    if (x == 0)
        cerr << "No Solutions\n";
    cout << ".\n";
    return x;
}



