#ifndef _NonCanon_H_
#define _NonCanon_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>

class NonCanon
{
    public:
	NonCanon(void);		// Constructor
	~NonCanon();		// Destructor
	
	char get(void) const;	// get the next char
	void echo(void);	// echo characters received
	void noecho(void);	// don't echo chrs
    private:
    	struct termios
		saved;
    	int
		init,		// setting succeeded: init = 1
		use_echo;	// default 0;
};
#endif
