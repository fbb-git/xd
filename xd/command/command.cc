#include "command.ih"

Command::Command()
:
    d_action(FROM_HOME),
    d_parent(0)
{
    string arguments;

    concatArgs(&arguments);

    bool subSpecs = determineAction(arguments);

    String::split(this, arguments, s_separators);

    if (!subSpecs && size() && ArgConfig::instance().nArgs() == 1)
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






