#include "command.ih"

bool Command::write(string const &path) const
{
    cout << path << endl;               // write the selected path
    return path != ".";                 // ret. true for real paths
}

    
    
