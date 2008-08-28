#include "alternatives.ih"

/*
    If d_home is false, d_addRoot can be set to false

    The Command object can return 
        
*/

string Alternatives::determineInitialDirectory()
{
    string cwd;
    auto_ptr<char> buffer;

    switch (d_command.action())
    {
        case Command::FROM_CONFIG:
            cwd = d_home ? d_config.homeDir() : "/";
        break;

        case Command::FROM_HOME:
            cwd = d_config.homeDir();
        break;

        case Command::FROM_ROOT:
            cwd = "/";
        break;

        case Command::FROM_CWD:
            getCwd(&buffer);
            cwd = buffer.get();
        break;

        case Command::FROM_PARENT:
            getCwd(&buffer);
            cwd = buffer.get();
            size_t pos = cwd.length();
            for (size_t idx = d_command.parent(); pos && idx--; )
                pos = cwd.rfind('/', pos - 1);

            if (pos > 0)
                cwd.resize(pos);
            else
            {
                cwd = '/';
                d_addRoot = FALSE;
            }
        break;
    }

    if (not d_home)
        d_addRoot = FALSE;

    if (Arg::instance().option('d'))
        cerr << "Resolved Cwd as: " << cwd << endl;

    if (*cwd.rbegin() != '/')         // all dirs end in /
        cwd += '/';

    return cwd;
}



