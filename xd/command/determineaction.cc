#include "command.ih"

bool Command::determineAction(string &args)
{                    
    switch (int ch = args[0])   // Interpret the first character
    {
        case '0':               // from parent 0 or cwd
            d_action = FROM_CWD;
        break;

        case '.':           // from HOME
            d_action = FROM_HOME;
        break;

        case '/':           // explicitly from the root
            d_action = FROM_ROOT;
        break;              // breaks remove the 1st char from args

        // start from a parent
        case '1':         
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            d_parent = ch - '0';
            d_action = FROM_PARENT;
        break;

        // other characters: 1st letter of directory
        default:
        {
            bool firstIsSeparator = (ch == '_');
            if (firstIsSeparator)
                args.erase(0, 1);      // remove the 1st char
            d_action = FROM_CONFIG;
            return firstIsSeparator;
        }
    }

    args.erase(0, 1);      // remove the 1st (location) character
    return false;
}
