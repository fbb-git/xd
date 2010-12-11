#ifndef _INCLUDED_ALTERNATIVES_H_
#define _INCLUDED_ALTERNATIVES_H_

#include <deque>
#include <vector>
#include <set>
#include <string>
#include <memory>

#include <bobcat/argconfig>

#include "../command/command.h"

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
    public:
        enum Separate
        {
            DONT,
            TOP,
            BOTTOM
        };

    private:
        struct HistoryInfo
        {
            size_t      time;
            size_t      count;
            std::string path;
        };

        friend std::istream &operator>>(std::istream &in, HistoryInfo &hl);
        friend std::ostream &operator<<(std::ostream &in, 
                                                    HistoryInfo const &hl);


        FBB::ArgConfig &d_arg;
    
        size_t d_nHistory;  // Number of history-alternatives encountered.
        bool d_home;    // true: search from $HOME
        bool d_dirs;    // true: search all dirs (also via links)
        size_t d_now;   // current time
    
        Separate d_historySep;
    
        size_t d_historyLifetime;
        size_t d_beginHistory;
        size_t d_endHistory;
        size_t d_separateAt;
                        
        std::string d_historyName;   // if not empty: name of the history
                                     // file 
        std::vector<HistoryInfo> d_history;

        std::string d_homeDir;

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
        static char const *const *const s_triStateEnd;

        static char const *s_startAt[];
        static char const * const *const s_startAtEnd;

        static char const *s_dirs[];
        static char const *const *const s_dirsEnd;
    
        static char const *s_merge[];
        static char const *const *const s_mergeEnd;
    
        static char s_defaultConfig[];
        static char s_defaultHistory[];
    
    public:
        Alternatives();
        void viable();
        void order();
        void updateHistory(size_t index) const;

        size_t beginHistory() const;
        size_t endHistory() const;
        size_t separateAt() const;

    private:
        void setHome();
        void setConfigFile();
        void setHistory();
        void setHistoryVars();
        void setHistoryLifetime();

        static void maybeInsert(HistoryInfo  const &historyInfo, 
                                std::vector<HistoryInfo> &history, 
                                size_t now);
        static bool compareGreater(HistoryInfo const &first, 
                                   HistoryInfo const &second);

                                        // see if a path is in the history
        std::vector<HistoryInfo>::const_iterator findHistory(
                                            std::string const &path) const;

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

        static bool findEntry(HistoryInfo const &history,
                                std::string const &entry);
};

inline void Alternatives::addPath(std::string const &element, 
                                                            std::string &path)
{
    path += element;
    path += "*/";
}


inline size_t Alternatives::separateAt() const
{
    return d_separateAt;
}

inline size_t Alternatives::beginHistory() const
{
    return d_beginHistory;
}

inline size_t Alternatives::endHistory() const
{
    return d_endHistory;
}

inline std::ostream &operator<<(std::ostream &out, 
                                Alternatives::HistoryInfo const &hi)
{
    return out << hi.time << ' ' << hi.count << ' ' << hi.path << '\n';    
}

#endif


