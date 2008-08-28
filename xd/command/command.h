#ifndef _INCLUDED_COMMAND_H_
#define _INCLUDED_COMMAND_H_

#include <string>
#include <vector>

// determine the command as received and the kind of action according to
// the received pattern.

class Command: public std::vector<std::string> 
                       // stores the elements of the pattern
{
    public:
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

    private:
        void concatArgs(std::string *args);
        inline static void catArg(char const *arg, std::string &dest);

        bool determineAction(std::string &args);
        
        inline static void add(char ch, std::vector<std::string> &cmd);
//        void buildPattern(std::string &arguments);
//        Action actionType(std::string &arguments);
//
//        void separated_pattern(char *); // set up separated pattern
//                                        // e.g., from xd ho fr t
//        void one_pattern(char *);       // set up single pattern
//                                        // e.g. from xd hft
};

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
