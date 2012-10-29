#include "alternatives.ih"

void Alternatives::globFilter(char const *entry, GlobContext &context) 
{
    imsg << "Inspecting `" << entry << "': ";
                            // if a trailing / was removed reinstall it.
    string dirEntry(entry);
    if (*dirEntry.rbegin() != '/')
        dirEntry += '/';
    
    if (
        find_if(
            context.ignore.begin(), context.ignore.end(),
            [&](std::string const &ignore)
            {
                return matchIgnore(ignore, dirEntry.c_str());
            }
        ) 
        != context.ignore.end())
    {
        imsg << "ignored" << endl;
        return;
    }

    string spec = entry;

    if  // ignore the . nd .. directories
    (
        spec.rfind("/.") == spec.length() - 2 ||
        spec.rfind("/..") == spec.length() - 3
    )
    {
        imsg << "dot-directory" << endl;
        return;
    }

    Stat stat(entry);

        // check if the entry name (globbed) is equal to the true path name
        // if not, the globbed name is a link to the true path
    if (!context.alternatives.d_dirs && stat.path() != spec)
    {
        imsg << "symlink" << endl;
        return;
    }

    if 
    (
        context.stored.insert(
            pair<size_t, size_t>(stat.inode(), stat.device())
        ).second == false           // entry already there
    )
    {
        imsg << "already available" << endl;
        return;
    }

    imsg << "ACCEPTED" << endl;

    context.alternatives.add(entry);
}

