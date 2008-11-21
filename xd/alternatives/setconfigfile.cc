#include "alternatives.ih"

void Alternatives::setConfigFile()
{
    string confName;
    if (d_arg.option(&confName, 'c'))
        d_arg.open(confName);
    else 
    {
        confName = d_homeDir + s_defaultConfig;
        Stat confStat(confName);
        if (confStat)
        {
            if (not confStat.mode() & Stat::UR)
                msg() << "Can't read " << confName << warning;
            else
                d_arg.open(confName);
        }
    }
    msg() << "Configuration file: " << confName << info;
}

