#ifndef INCLUDED_HISTORY_
#define INCLUDED_HISTORY_

#include <string>
#include <vector>
#include <iostream>

namespace FBB
{
    class ArgConfig;
}

class History
{

//    public:

        enum Separate
        {
            DONT,
            TOP,
            BOTTOM
        };

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

        size_t d_now;   // current time
    
        Separate d_separator;
    
        size_t d_lifetime;
        size_t d_begin;
        size_t d_end;
        size_t d_separateAt;
                        
        std::string d_name;             // if not empty: name of the history
                                        // file 
        std::vector<HistoryInfo> d_history;

        static char s_defaultHistory[];
    
    public:
        History(FBB::ArgConfig &arg, std::string const &homeDir);

// TO DO:
        void setLocation(size_t nInHistory);
// TO DO:
        void save(size_t index, std::string const &choice) const;
// TO DO:
        bool rotate() const;

    private:
        void load(std::string const &homeDir);
        void setData();

        static void maybeInsert(HistoryInfo  const &historyInfo, 
                                std::vector<HistoryInfo> &history, 
                                size_t now);
        static bool compareGreater(HistoryInfo const &first, 
                                   HistoryInfo const &second);

                                        // see if a path is in the history
        std::vector<HistoryInfo>::const_iterator findHistory(
                                            std::string const &path) const;

        static bool findEntry(HistoryInfo const &history,
                              std::string const &entry);

};

inline std::ostream &operator<<(std::ostream &out, 
                                History::HistoryInfo const &hi)
{
    return out << hi.time << ' ' << hi.count << ' ' << hi.path << '\n';    
}

inline bool History::rotate() const
{
    return not (d_name.empty() || d_history.empty());
// TO DO:   || d_historySep != BOTTOM)
}
        
#endif








