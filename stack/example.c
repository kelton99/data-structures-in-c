#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#ifdef _WIN32
	void clear_console() { system("cls"); }
#else
	void clear_console() { system("clear"); }
#endif

enum options {OPT_EXIT, OPT_PUSH, OPT_POP, OPT_INVERT, OPT_HELP};

int main(void)
{

}