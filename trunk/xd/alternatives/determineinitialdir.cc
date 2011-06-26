#include "alternatives.ih"

string Alternatives::determineInitialDirectory()
{
    string cwd;
    unique_ptr<char> buffer;
    bool rescan = false;

    switch (d_command.action())
    {
        case Command::FROM_CONFIG:
            cwd = d_home ? d_homeDir : string("/");
            rescan = true;
        break;

        case Command::FROM_HOME:
            cwd = d_homeDir;
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
                cwd = '/';
        break;
    }

    if (d_addRoot != FALSE && (!d_home || !rescan))
    {
        imsg << "Search does not start at the home dir: "
                "no additional search from the root" << endl;

        d_addRoot = FALSE;
    }

    imsg << "Resolved Cwd as: " << cwd << endl;

    if (*cwd.rbegin() != '/')         // all dirs end in /
        cwd += '/';

    return cwd;
}



