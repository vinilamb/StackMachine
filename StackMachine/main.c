#include <stdio.h>
#include "stackmachine.h"
#include "parser.h"
#include "interactive.h"

void main(char ** argv, int argc)
{
	//printf("Stack machine program\n");
	//printf("Usage - StackMachine.exe <mode> [arguments required by mode...]\n");
	//printf("Modes: \n");
	//printf("    i - Interactive.\n");
	//printf("    f - File execute.\n");
	//printf("    s - Syntax check.\n");
	SM_t sm;
	sm_init(&sm);
	launch_interactive_loop(&sm);
}