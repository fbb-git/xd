#ifndef INCLUDED_HISTORY_
#define INCLUDED_HISTORY_

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

namespace FBB
{
    class ArgConfig;
}

class History
{
    public:
        enum Position
        {
            TOP,
            BOTTOM
        };

    private:
        struct HistoryInfo
        {
            size_t      time;
            size_t      count;
            std::string path;

            HistoryInfo() = default;
            HistoryInfo(size_t time, size_t count, std::string const &path);
        };
    
        friend std::istream &operator>>(std::istream &in, HistoryInfo &hl);
        friend std::ostream &operator<<(std::ostream &in, 
                                                    HistoryInfo const &hl);
    
        FBB::ArgConfig &d_arg;
    
        size_t d_now;                   // current time
    
        size_t d_oldest;
        Position d_position;            // TOP or BOTTOM (TOP)
        std::string d_name;             // name of the history file 
                                        // (empty: no history used)
    
        std::vector<HistoryInfo> d_history;
    
        static char s_defaultHistory[];
        
    public:
        History(FBB::ArgConfig &arg, std::string const &homeDir);
        void setLocation(size_t nInHistory);
        void save(std::string const &choice);
        bool rotate() const;
        Position position() const;
                                        // see if a path is in the history
        bool find(std::string const &path) const;

    private:
        std::vector<HistoryInfo>::const_iterator findIter(
                                            std::string const &path) const;


        void load(std::string const &homeDir);
        void setData();

        static void maybeInsert(HistoryInfo  const &historyInfo, 
                                std::vector<HistoryInfo> &history, 
                                size_t now);
        static bool compareTimes(HistoryInfo const &first, 
                                 HistoryInfo const &second);
        static bool compareCounts(HistoryInfo const &first, 
                                  HistoryInfo const &second);

//        static bool findEntry(HistoryInfo const &history,
//                              std::string const &entry);

};

inline History::HistoryInfo::HistoryInfo(size_t time, size_t count, 
                                                    std::string const &path)
:
    time(time),
    count(count),
    path(path)
{}

inline History::Position History::position() const
{
    return d_position;
}

inline std::vector<History::HistoryInfo>::const_iterator History::findIter(
                                                std::string const &path) const
{
    return 
        find_if(
            d_history.begin(), d_history.end(), 
            [&](HistoryInfo const &history)
            {
                return history.path == path;
            }
        );
}

inline bool History::find(std::string const &path) const
{
    return findIter(path) != d_history.end();
}

inline std::ostream &operator<<(std::ostream &out, 
                                History::HistoryInfo const &hi)
{
    return out << hi.time << ' ' << hi.count << ' ' << hi.path;   
}

inline bool History::rotate() const
{
    return d_name.length() && d_position == BOTTOM;
}
        
#endif








