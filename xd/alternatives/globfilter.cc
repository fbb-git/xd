#include "alternatives.ih"

void Alternatives::globFilter(char const *entry, GlobContext &context) 
{
    Stat stat(entry);

    if (!stat.isType(Stat::DIRECTORY))
        return;

        // check if the entry name (globbed) is equal to the true path name
        // if not, the globbed name is a link to the true path
    if (!context.alternatives.d_dirs && stat.path() != entry)
        return;

    if 
    (
        context.stored.insert(
            pair<size_t, size_t>(stat.inode(), stat.device())
        ).second == false           // entry already there
    )
        return;

    context.alternatives.push_back(entry);
}
