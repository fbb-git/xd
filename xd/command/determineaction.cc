#include "command.ih"

//    Possibilities:
//        either with or without using 'home no'. When a special case
//        arises, it is indicated.
//
//    ----------------------------------------------------------
//                            using sub-specifications 
//                           (/ and - separate subspecs)
//    ----------------------------------------------------------
//    intention               no              yes
//    ----------------------------------------------------------
//    from CWD              .abc (11)       ./a/bc (12)
//                                          ./abc
//
//    from $HOME            0abc (21)       0/a/bc  (22)
//                                          0.  (all .* dirs at $HOME)
//         
//    from /                /abc (31)       /a/bc  (32)
//                          /               //abc
//                          (/ sitches to the root directory only)
//
//    from cwd's parent #   #abc (41)       #a/bc  (42)
//    (#: [1-9])                            #/abc
//         
//    from config           abc  (51)       -abc    (51)
//      (- can be used as a pattern indicator at the 1st position)
//    ----------------------------------------------------------
//
//    command[0] determines the initial cell:
//        0   indicates from the current directory onward
//        .   indicates subspecifications from $HOME
//        /   indicates from the root
//        #   (#: [1-9]) indicates specifications from parent #
//        other   indicates from $HOME
//
//        any / or - beyond command[0] automatically switches to
//        sub-specifications (the last / on command is not counted
//        here, as this one was added by Command() itself.

bool Command::determineAction(string &args)
{                    
    switch (int ch = *args.begin()) // Interpret the first character
    {
        case '0':           // from parent 0 or cwd (cells 41, 42)
            d_action = FROM_CWD;
        break;

        case '.':           // from HOME (21, 22)
            d_action = FROM_HOME;
        break;

        case '/':           // explicitly from the root: cells 31, 32
            d_action = FROM_ROOT;
        break;              // breaks remove the 1st char from args

        // start from a parent (cells 41, 42)
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

        // other characters: 1st letter of directory (cell 51)
        default:
        {
            bool firstIsMinus = (ch == '-');
            if (firstIsMinus)
                args.erase(0, 1);      // remove the 1st char
            d_action = FROM_CONFIG;
            return firstIsMinus;
        }
    }

    args.erase(0, 1);      // remove the 1st (location) character
    return false;
}
