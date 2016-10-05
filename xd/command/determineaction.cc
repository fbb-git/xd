#include "command.ih"

void Command::determineAction()
{                    
    switch (int ch = d_arguments[0])   // Interpret the first character
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
        case '1' ... '9':         
            d_parent = ch - '0';
            d_action = FROM_PARENT;
        break;

        // other characters: 1st char. of directory
        default:
//        {
//            bool firstIsSeparator = (ch == '_');
//            if (firstIsSeparator)
//                d_arguments.erase(0, 1);      // remove the 1st char
            d_action = FROM_CONFIG;
        return;
//            return firstIsSeparator;
//        }
    }

    do
        d_arguments.erase(0, 1);      // remove the 1st (location) character
    while (d_arguments.front() == '/'); // and a possible initial / sep.

    imsg << "Removed the location character: `" << 
                                            d_arguments << '\'' << endl;
}
