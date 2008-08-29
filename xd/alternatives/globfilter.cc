#include "alternatives.ih"

void Alternatives::globFilter(char const *entry, GlobContext &context) 
{
    Stat stat(entry);

    msg() << "Inspecting `" << entry << "': " << spool;

    if (!stat.isType(Stat::DIRECTORY))
    {
        msg() << "no directory" << info;
        return;
    }

    string spec = entry;

    if  // ignore the . nd .. directories
    (
        spec.rfind("/.") == spec.length() - 2 ||
        spec.rfind("/..") == spec.length() - 3
    )
    {
        msg() << "dot-directory" << info;
        return;
    }

        // check if the entry name (globbed) is equal to the true path name
        // if not, the globbed name is a link to the true path
    if (!context.alternatives.d_dirs && stat.path() != spec)
    {
        msg() << "symlink" << info;
        return;
    }


    if 
    (
        context.stored.insert(
            pair<size_t, size_t>(stat.inode(), stat.device())
        ).second == false           // entry already there
    )
    {
        msg() << "already available" << info;
        return;
    }

    msg() << "ACCEPTED" << info;

    context.alternatives.push_back(entry);
}
