#ifndef _INCLUDED_COMMAND_H_
#define _INCLUDED_COMMAND_H_

#include <string>
#include <vector>

// determine the command as received and the kind of action according to
// the received pattern.

class Command: public std::vector<std::string> 
                       // stores the elements of the pattern
{
    static char const *s_action[];
    static char const s_separators[];   // separating parts of nested dir
                                        // names 
    public:
        // modify commanddata.cc if Action is modified
        enum Action                     // starting point as determined 
        {                               // by the first arg-character
            FROM_CONFIG,                // default: determined by config
            FROM_HOME,
            FROM_ROOT,
            FROM_CWD,
            FROM_PARENT,                // relative to CWD
        };

    private:
        Action d_action;
        size_t d_parent;                

    public:
        Command();      
        inline size_t parent() const;
        inline Action action() const;

    private:
        void concatArgs(std::string *args);
        inline static void catArg(char const *arg, std::string &dest);

        bool determineAction(std::string &args);
        
        inline static void add(char ch, std::vector<std::string> &cmd);
};

size_t Command::parent() const
{
    return d_parent;
}

Command::Action Command::action() const
{
    return d_action;
}

void Command::catArg(char const *arg, std::string &dest)
{
    dest += arg;
    dest += '/';
}

void Command::add(char ch, std::vector<std::string> &cmd)
{
    cmd.push_back(std::string(1, ch));
}

#endif
