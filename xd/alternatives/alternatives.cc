#include "alternatives.ih"

Alternatives::Alternatives()
:
    d_arg(ArgConfig::instance())
{
    setHome();
    setConfigFile();
}
