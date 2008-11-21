#include "alternatives.ih"

// abcd is handled as:
// 
// 1. a*/ test bcd 
//     
// 1.1. a*/b* test cd (etc).
// 
// 2.  ab*/ test cd (etc). 
// 
// but if a/bcd is entered:
// 
// 1. a*/ test /bcd
// 
// 1.1 a*/b* test cd (etc)
// 
// 2.  a/b:    not tested
// 3.  a/bc:   not tested
// 4.  a/bcd:  not tested
// 
// So: if the head contains a / it is not tested.
// If the tail starts with /, that char is ignored.

void Alternatives::globPattern(string pattern, 
                                string const &searchCmd, size_t idx,
                                GlobContext &context)
try
{
        // create a pattern from pattern + initial substring
    string head = searchCmd.substr(0, idx);

    if (head.find('/') != string::npos)
        throw false;    // caught by globHead

    pattern += head;
    pattern += "*/";

    if (idx != searchCmd.length())
    {
        string tail = searchCmd.substr(idx);
        globHead(pattern, tail[0] == '/' ? tail.substr(1) : tail, context);
    }
    else
    {
        msg() << "Globbing merged pattern `" << pattern << '\'' << info;
        Glob glob(pattern, Glob::NOSORT, Glob::DEFAULT);
        // verify() not called since we're ignoring exceptions here

        for_each(glob.begin(), glob.end(), 
             FnWrap1c<char const *, GlobContext &>(globFilter, context));
   }
}
catch (Errno const &err)      // to catch exceptions from glob
{}
