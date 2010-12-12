#ifndef _INCLUDED_ALTERNATIVES_H_
#define _INCLUDED_ALTERNATIVES_H_

#include <deque>
#include <vector>
#include <set>
#include <string>
#include <memory>


#include "../command/command.h"
#include "../history/history.h"

namespace FBB
{
    class ArgConfig;
}


#if 0
| 
|     If, when looking for /t*/m*/ps*/ the initial path /t*/m* does not exist
| then there's no reason for inspecting /t*/mp*/s*/ as it won't exist either.
| 
| In those cases the non-existing path is pruned (i.e., t*/m* is) an 
| subpatterns of the pruned path (e.g., t*/mp*) are not considered (and so:
| not globbed)
| 
#endif


class Alternatives: public std::deque<std::string>
{
    private:

        std::string d_homeDir;
        FBB::ArgConfig &d_arg;
        bool d_separate;
        size_t d_nInHistory;

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
        History d_history;

        static char const *s_triState[];
        static char const *const *const s_triStateEnd;

        static char const *s_startAt[];
        static char const * const *const s_startAtEnd;

        static char const *s_dirs[];
        static char const *const *const s_dirsEnd;
    
        static char const *s_merge[];
        static char const *const *const s_mergeEnd;

        static char s_defaultConfig[];
    
    public:
        Alternatives();
        void viable();
        void order();
        void update(size_t idx);

        size_t beginHistory() const;
        size_t endHistory() const;
        size_t separateAt() const;

    private:
        static std::string getHome();

        FBB::ArgConfig &configFile();



        size_t set(char const *longKey, char const *const * const begin, 
                                    char const *const *const end, 
                                    size_t notFound);

        void getCwd(std::unique_ptr<char> *dest);

        std::string determineInitialDirectory();        
        void globFrom(std::string initial);
    
        void add(char const *path);         // also determines d_nPatterns

        struct GlobContext
        {
            Alternatives &alternatives;
            std::set<std::pair<size_t, size_t> > stored;
            std::set<std::string> ignore;
        };
        void glob(std::string initial, GlobContext &context);

        void generalizedGlob(std::string initial, GlobContext &context);
        void globHead(std::string const &initial, 
                      std::string searchCmd, GlobContext &context);
        void globPattern(std::string pattern, 
                                std::string const &searchCmd, size_t idx,
                                GlobContext &context);

        inline static void addPath(std::string const &element, 
                                    std::string &path);

        static void globFilter(char const *entry, GlobContext &context);

        static void addIgnored(std::string const &line, 
                                std::set<std::string> &ignoreSet);

        static bool matchIgnore(std::string const &ignore, char const *entry);

};

inline void Alternatives::update(size_t index)
{
    d_history.save((*this)[index]);
}

inline void Alternatives::addPath(std::string const &element, 
                                                            std::string &path)
{
    path += element;
    path += "*/";
}


inline size_t Alternatives::beginHistory() const
{
    return d_history.position() == History::TOP ? 0 : size() - d_nInHistory;
}

inline size_t Alternatives::endHistory() const
{
    return d_history.position() == History::TOP ? d_nInHistory : size();
}

#endif


