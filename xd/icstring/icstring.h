/*
				S t r i n g . h

*/

#ifndef _ICString_H_
#   define _ICString_H_

#include <malloc.h>
#include <string.h>

class ICString
{
    public:
	ICString(void);			// default constructor
	~ICString();			// destructor (2)

	ICString(const ICString &other);// copy constructor (3)
					// assign.cc
	ICString const& operator= (const ICString &other);	

	unsigned get_count(void) const;	// return # of strings
					// return string given index
	char const *get_string(unsigned index) const;
    
	void add (char const *str);	// add new string

	void remove(int index);		// remove string, given index
					// note: indexes will change !

					// get index of target (or 0xffff)
	unsigned get_index(char const *target) const;

        void setup (unsigned count,     // fill with vector of strings
                    char const* const* vector);
    private:
	void copy(unsigned count, char const* const* vector);
    
	void destroy(void);			// internal destructor

	unsigned
		count;			// number of strings in the array
	char
		**vector;		// vector of string pointers
};

#endif
