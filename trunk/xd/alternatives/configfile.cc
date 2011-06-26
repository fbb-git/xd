#include "alternatives.ih"

ArgConfig &Alternatives::configFile()
{
    ArgConfig &arg = ArgConfig::instance();

    string confName;
    if (arg.option(&confName, 'c'))
        arg.open(confName);
    else 
    {
        confName = d_homeDir + s_defaultConfig;
        Stat confStat(confName);
        if (confStat)
        {
            if (not confStat.mode() & Stat::UR)
                wmsg << "Can't read " << confName << endl;
            else
                arg.open(confName);
        }
    }
    imsg << "Configuration file: " << confName << endl;

    return arg;
}

