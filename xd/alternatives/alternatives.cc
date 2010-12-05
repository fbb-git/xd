#include "alternatives.ih"

Alternatives::Alternatives()
:
    d_arg(ArgConfig::instance()),
    d_nPopular(0),              // 0 popular alternatives encountered so far.
    d_beginPopular(0),
    d_endPopular(0)
{
    setHome();
    setConfigFile();

    string str;                 // to be removed fm bobcat 2.09.03
    d_popularFirst = not d_arg.option(&str, "popular-last");
    d_separateAt = d_arg.option(&str, "popular-separate"); // modified in
                                                            // setPopular
    setPopular();
}
