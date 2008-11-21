#include "command.ih"

Command::Command()
:
    d_action(FROM_HOME),
    d_parent(0)
{
    concatArgs();

    bool subSpecs = determineAction();

    String::split(this, d_arguments, s_separators);

    // When are the elements of the first argument changed into initial chars
    // of directory elements?
    // 1. if there is only one command line argument 
    // 2. if the first argument is not to be interpreted as a name by itself
    // 3. if there's only one argument
    // Can't 2 and 3 be combined to: size() == 1 ?
//    if (!subSpecs && size() && ArgConfig::instance().nArgs() == 1)
    if (!subSpecs && size() == 1)
    {
        for_each(front().begin() + 1, front().end(), 
            FnWrap1c<char, vector<string> &>(add, *this));
        front().resize(1);
    }

    if (ArgConfig::instance().option('V'))
    {
        cerr << "Parent nr: " << d_parent << "\n"
                "Action: " << s_action[d_action] << "\n"
                "Initial characters of directories: ";
        copy(begin(), end(), ostream_iterator<string>(cerr, " "));
        cerr << endl;
    }
}



