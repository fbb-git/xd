#include "command.ih"

Command::Command()
:
    d_action(FROM_HOME),
    d_parent(0)
{
    string arguments;

    concatArgs(&arguments);

    bool subSpecs = determineAction(arguments);

    String::split(this, arguments, "/-");
    if (!subSpecs && size() && Arg::instance().nArgs() == 1)
    {
        for_each(front().begin() + 1, front().end(), 
            FnWrap1c<char, vector<string> &>(add, *this));
        front().resize(1);
    }

    if (Arg::instance().option('d'))
    {
        cerr << "Parent nr: " << d_parent << "\n"
                "Action: " << s_action[d_action] << "\n"
                "Initial characters of directories: ";
        copy(begin(), end(), ostream_iterator<string>(cerr, " "));
        cerr << endl;
    }
}






