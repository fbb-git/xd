#include "noncanon.h"

NonCanon::NonCanon(void)
{
	use_echo = 0;
	init = 0;
	
	if
	(
		!isatty(STDIN_FILENO)
		||
		tcgetattr(STDIN_FILENO, &saved)
	)
		return;
	
	struct termios
		tattr;

	tcgetattr(STDIN_FILENO, &tattr);	// can't assign here ??
	
	tattr.c_lflag &= ~(ICANON | ECHO);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	
	init = !tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr);
}
	
