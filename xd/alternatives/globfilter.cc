#include "alternatives.ih"

void Alternatives::globFilter(char const *entry, GlobContext &context) 
{
    Stat stat(entry);

    if (!stat.isType(Stat::DIRECTORY))
        return;

    if 
    (
        context.stored.insert(
            pair<size_t, size_t>(stat.inode(), stat.device())
        ).second == false           // entry already there
    )
        return;

    context.dest.push_back(entry);
}
