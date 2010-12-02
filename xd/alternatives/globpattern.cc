#include "alternatives.ih"

// abcd is handled as:
// 
// 1. a*/       if existing: test bcd else leave.
//     
// 1.1. a*/b*   if existing: test cd else leave (etc).
// 
// 2.  ab*/ test cd (etc). 
// 
// but if a/bcd is entered:
// 
// 1. a*/       if existing: test /bcd, else leave
// 
// 1.1 a*/b*    if existing: test cd, else leave (etc)
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

    if (head.find('/') != string::npos)     // ignore if head has a /
        throw false;                        // caught by globHead

    pattern += head;
    pattern += "*/";                        // this pattern must exist

    Glob glob(pattern, Glob::NOSORT, Glob::DEFAULT);
    imsg << "Pattern `" << pattern << "', " << glob.size() << 
            " matches" << endl;

    if (idx != searchCmd.length())
    {
        string tail = searchCmd.substr(idx);
        globHead(pattern, tail[0] == '/' ? tail.substr(1) : tail, context);
    }
    else
    {
        for_each(glob.begin(), glob.end(), 
                    FnWrap::unary(globFilter, context));
   }
}
catch (Errno const &err)      // to catch exceptions from glob
{
    imsg << "No pattern matching `" << pattern << "', pruning this branch" <<
            endl;

    throw false;
}






