
#ifndef _ERROR_H_
#define _ERROR_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h> 
#include <malloc.h> 
#include <unistd.h>

class ICError
{
    public:
	ICError(char const *prog = 0);
	ICError(FILE *stream, char const *prog = 0);

	ICError(ICError const &other);
	~ICError();				// destructor
	
	ICError const &operator=(ICError const &right);
	

	void use_FILE(FILE *stream);		// switch to another file
        void use_program(char const *prog);     // set the program
	
	void fatal(char const *fmt, ...);
	int message(char const *fmt, ...);	// returns 1
	void copyright(char const *function,	// displays copyright notice
		char const *version,		// to stderr
		char const *years, int distribution);
    private:
    	void setprogram(char const *prog);
	void msg(char const *fmt, va_list args);
	
    	FILE
		*stream;		// straight duplication
	char
		*program;		// if 0, no program is mentioned
};

#endif
