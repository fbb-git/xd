#include "Match.h"

Match::~Match()
{
    for (unsigned i = 0; i < glob_struct.gl_pathc; i++)
       delete glob_struct.gl_pathv[i];
       
    delete glob_struct.gl_pathv;

    for (unsigned i = 0; i < extra_glob.gl_pathc; i++)
       delete extra_glob.gl_pathv[i];
       
    delete extra_glob.gl_pathv;

    delete id;              // delete the Id's
}
