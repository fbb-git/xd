#include "Match.h"

int Match::lookup(ino_t inode, dev_t device) const
{
    for (register unsigned index = 0; index < n; index++)
    {
        if
        (
            id[index].inode == inode        // same file
            &&
            id[index].device == device      // same file
        )
            return (1);
    }

    return (0);                 // not found
}
