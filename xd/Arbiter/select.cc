#include "Arbiter.h"

void Arbiter::select(void)
{
	NonCanon
		nckbd;
	register unsigned
	    c;

	c = nckbd.get();		    // get the replay

	number = 
	    '0' <= c && c <= '9' ?
		c  - '0' 		    // numbers < 10
	    :
		c - ('a' - 10);		    // numbers above 10

	if (number > count)		    // none selected
		number = 0;

}
