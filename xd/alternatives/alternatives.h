#ifndef _INCLUDED_ALTERNATIVES_H_
#define _INCLUDED_ALTERNATIVES_H_

#include <vector>
#include <set>
#include <string>
#include <memory>

#include "../config/config.h"
#include "../command/command.h"

class Alternatives: public std::vector<std::string>
{
    Config d_config;
    bool d_ok;
    bool d_home;    // true: search from $HOME
    bool d_dirs;    // true: search all dirs (also via links)

    enum TriState
    {
        FALSE,
        IF_EMPTY,
        TRUE
    };

    
    TriState d_addRoot; // true: always also search /, ifEmpty: only if 
                        //      search from $HOME fails
 
    Command d_command;

    static char const *s_triState[];
    static char const **s_triStateEnd;

    public:
        Alternatives();
        inline operator bool() const;

        void viable();

    private:
        bool set(char const *key, char const *trueText);
        size_t set(char const *key, char const **begin, char const **end, 
                                    size_t notFound);

        void getCwd(std::auto_ptr<char> *dest);

        std::string determineInitialDirectory();        
        void globFrom(std::string initial);
        void glob(std::string initial, 
                    std::set<std::pair<size_t, size_t> > &stored);

        inline static void addPath(std::string const &element, 
                                                        std::string &path);

        struct GlobContext
        {
            std::set<std::pair<size_t, size_t> > &stored;
            Alternatives &alternatives;
        };
        static void globFilter(char const *entry, GlobContext &context);
};

void Alternatives::addPath(std::string const &element, std::string &path)
{
    path += element;
    path += "*/";
}

Alternatives::operator bool() const
{
    return d_ok;
}

#endif


