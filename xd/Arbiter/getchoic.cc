#include "Arbiter.h" 

char const *Arbiter::get_choice(void)
{
	return
	(
		number ?
			match->get_string(number - 1)
		:
			"."
	);
}	
