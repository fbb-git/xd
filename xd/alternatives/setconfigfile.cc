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
                wmsg << "Can't read " << confName << endl;
            else
                d_arg.open(confName);
        }
    }
    imsg << "Configuration file: " << confName << endl;
}

